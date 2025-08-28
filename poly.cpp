#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <climits>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class PolynomialInterpolator {
private:
    static int digitVal(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
        if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
        return -1;
    }

    static long long decodeBase(const string& s, int base) {
        if (s.empty()) throw runtime_error("empty value");
        if (base < 2 || base > 36) throw runtime_error("base out of range [2-36]");
        
        long long ans = 0;
        for (char c : s) {
            int d = digitVal(c);
            if (d < 0 || d >= base) {
                throw runtime_error("invalid digit '" + string(1, c) + 
                                  "' for base " + to_string(base));
            }
            if (ans > (LLONG_MAX - d) / base) {
                throw overflow_error("value too large for long long");
            }
            ans = ans * base + d;
        }
        return ans;
    }

    static double lagrangeConstAtZero(const vector<long long>& X, 
                                     const vector<long long>& Y) {
        if (X.size() != Y.size() || X.empty()) {
            throw runtime_error("invalid point arrays");
        }

        int n = static_cast<int>(X.size());
        double res = 0.0;
        
        for (int i = 0; i < n; i++) {
            double term = static_cast<double>(Y[i]);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long denomLL = X[i] - X[j];
                if (denomLL == 0) {
                    throw runtime_error("duplicate x value detected at indices " + 
                                      to_string(i) + " and " + to_string(j));
                }
                term *= (-static_cast<double>(X[j])) / static_cast<double>(denomLL);
            }
            res += term;
        }
        return res;
    }

    static int readIntLoose(const json& j) {
        if (j.is_number_integer()) return j.get<int>();
        if (j.is_string()) return stoi(j.get<string>());
        throw runtime_error("expected int or string number");
    }

    static string readStringLoose(const json& j) {
        if (j.is_string()) return j.get<string>();
        if (j.is_number_integer()) return to_string(j.get<long long>());
        throw runtime_error("expected string or integer");
    }

public:
    static long long solve(const string& input) {
        if (input.empty() || input.find_first_not_of(" \t\r\n") == string::npos) {
            throw runtime_error("empty input");
        }

        // Parse JSON
        json data = json::parse(input);

        // Validate and read n, k
        if (!data.contains("keys")) {
            throw runtime_error("missing 'keys' object");
        }
        const json& K = data["keys"];
        if (!K.contains("n") || !K.contains("k")) {
            throw runtime_error("missing n/k under 'keys'");
        }

        int n = readIntLoose(K["n"]);
        int k = readIntLoose(K["k"]);
        if (n <= 0 || k <= 0 || k > n) {
            throw runtime_error("invalid n=" + to_string(n) + 
                              " or k=" + to_string(k));
        }

        // Collect points
        vector<pair<long long, long long>> pts;
        pts.reserve(n);
        
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it.key() == "keys") continue;

            try {
                long long x = stoll(it.key());
                const json& obj = it.value();
                
                if (!obj.is_object()) {
                    throw runtime_error("point is not an object");
                }
                if (!obj.contains("base") || !obj.contains("value")) {
                    throw runtime_error("missing base/value");
                }

                int base = readIntLoose(obj["base"]);
                string val = readStringLoose(obj["value"]);
                long long y = decodeBase(val, base);

                pts.emplace_back(x, y);
            } catch (const exception& e) {
                throw runtime_error("Error at point " + it.key() + ": " + e.what());
            }
        }

        if (static_cast<int>(pts.size()) < k) {
            throw runtime_error("not enough points: need " + to_string(k) + 
                              ", got " + to_string(pts.size()));
        }

        // Process points
        sort(pts.begin(), pts.end());
        pts.resize(k);

        vector<long long> X, Y;
        X.reserve(k); 
        Y.reserve(k);
        for (const auto& p : pts) {
            X.push_back(p.first);
            Y.push_back(p.second);
        }

        return llround(lagrangeConstAtZero(X, Y));
    }
};

int main(int argc, char* argv[]) {
    try {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // Read input
        string input;
        if (argc >= 2 && string(argv[1]) != "-") {
            ifstream f(argv[1], ios::binary);
            if (!f.is_open()) {
                throw runtime_error("cannot open file: " + string(argv[1]));
            }
            input.assign(istreambuf_iterator<char>(f), 
                        istreambuf_iterator<char>());
        } else {
            input.assign(istreambuf_iterator<char>(cin), 
                        istreambuf_iterator<char>());
        }

        // Handle UTF-8 BOM
        if (input.size() >= 3 && 
            static_cast<unsigned char>(input[0]) == 0xEF &&
            static_cast<unsigned char>(input[1]) == 0xBB &&
            static_cast<unsigned char>(input[2]) == 0xBF) {
            input.erase(0, 3);
        }

        cout << PolynomialInterpolator::solve(input) << "\n";
        return 0;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
