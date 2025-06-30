class Solution {
   void helper(int idx, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (idx == arr.size()) {
        ans.push_back(ds);
        return;
    }

    // pick
    ds.push_back(arr[idx]);
    helper(idx + 1, arr, ans, ds);
    ds.pop_back();

    // not pick
    helper(idx + 1, arr, ans, ds);
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,nums,ans,ds);
        return ans;
    }
};