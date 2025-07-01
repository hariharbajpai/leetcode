class Solution {
    void helper(int idx, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        ans.push_back(ds);  // include current subset

        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1]) continue;  // skip duplicate

            ds.push_back(arr[i]);
            helper(i + 1, arr, ans, ds);
            ds.pop_back();  // backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,nums,ans,ds);
        return ans;
    }
};