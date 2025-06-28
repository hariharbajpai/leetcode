class Solution {
public:
    string defangIPaddr(string address) {
        queue<char> q;
        
        for(char c : address) {
            if(c == '.') {
                q.push('[');
                q.push('.');
                q.push(']');
            } else {
                q.push(c);
            }
        }
        
        string result;
        while(!q.empty()) {
            result += q.front();
            q.pop();
        }
        
        return result;
    }
};