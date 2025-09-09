class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
    int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;                 // indices with unresolved NGE

        for (int i = 0; i < 2 * n; ++i) {
            int cur = arr[i % n];
            // Resolve anything smaller than current
            while (!st.empty() && arr[st.top()] < cur) {
                ans[st.top()] = cur;
                st.pop();
            }
            // Only push indices in the first pass
            if (i < n) st.push(i);
        }
        return ans;
    }
};
