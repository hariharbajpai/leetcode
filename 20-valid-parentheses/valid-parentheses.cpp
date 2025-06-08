class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if(stack.empty()) {
                    return false;
                }
                char top = stack.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};