class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;          // store indices
        vector<int> ans(n, 1);  // spans

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return ans;
    }
};
