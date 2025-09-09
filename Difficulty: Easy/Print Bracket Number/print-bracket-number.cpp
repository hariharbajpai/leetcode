// Bracket Numbers (stack approach)
class Solution {
public:
    vector<int> bracketNumbers(const string& s) {
        stack<int> st;
        vector<int> out;
        int id = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(++id);          
                out.push_back(st.top());
            } else if (c == ')') {
                if (!st.empty()) {
                    out.push_back(st.top());
                    st.pop();
                }
            }
             
        }
        return out;  
    }
};
