#include <unordered_map>

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;

        for (char c : t) {
            freq[c]++;
        }

        for (char c : s) {
            freq[c]--;
        }

        for (auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return '\0';  
    }
};