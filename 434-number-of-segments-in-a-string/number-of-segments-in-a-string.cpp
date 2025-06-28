class Solution {
public:
    int countSegments(string s) {
        stack<char> st;
        int cnt = 0;
        bool inSegment = false;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                st.push(s[i]);
                if(!inSegment) {
                    cnt++;
                    inSegment = true;
                }
            } else {
                inSegment = false;
                while(!st.empty()) {
                    st.pop();
                }
            }
        }
        return cnt;
    }
};