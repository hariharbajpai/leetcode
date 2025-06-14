class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stk;
         
        for(char c : s) {
            stk.push(c);
        }
        
        
        for(int i = 0; i < s.size(); i++) {
            s[i] = stk.top();
            stk.pop();
        }
    }
};