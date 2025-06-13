class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char ch : s) {
            if (isdigit(ch)) {
                if (!st.empty()) st.pop(); // Remove the last character before digit
            } else {
                st.push(ch); // Push character if it's not a digit
            }
        }

        // Reconstruct the string from stack (in correct order)
        string result;
        while (!st.empty()) {
            result = st.top() + result; // prepend to maintain original order
            st.pop();
        }

        return result;
    }
};
