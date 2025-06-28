class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char> st;
        bool wordFound = false;   
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                st.push(s[i]);   
                wordFound = true;
            } else if (wordFound) {
                break;  
            }
        }
        
        return st.size();   
    }
};