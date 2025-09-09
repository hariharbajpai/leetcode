// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;

        for (int i = 0; i < (int)arr.size(); i++) {
            if (st.empty()) {
                st.push(arr[i]);
            } else if (arr[i] < 0) {                 // current is negative
                if (st.top() < 0) st.push(arr[i]);   // same sign -> keep
                else st.pop();                       // opposite sign -> remove pair
            } else {                                 // current is non-negative (0 included)
                if (st.top() >= 0) st.push(arr[i]);  // same sign -> keep
                else st.pop();                       // opposite sign -> remove pair
            }
        }

        // Unwind to vector in original order
        vector<int> res(st.size());
        for (int i = (int)res.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
