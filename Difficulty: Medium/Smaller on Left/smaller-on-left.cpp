class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // store indices with increasing values

        for (int i = 0; i < n; ++i) {
            // maintain strictly increasing stack by value
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if (!st.empty()) ans[i] = arr[st.top()]; // nearest smaller on left
            // push current index
            st.push(i);
        }
        return ans;
    }
};
