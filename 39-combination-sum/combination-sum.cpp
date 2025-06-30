class Solution {
    void findCombinations(int idx, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds) {
        if (idx == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick the current index element (if it doesn’t exceed target)
        if (arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findCombinations(idx, arr, target - arr[idx], ans, ds); // not idx+1, since we can reuse same element
            ds.pop_back();
        }

        // not pick the element
        findCombinations(idx + 1, arr, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};
