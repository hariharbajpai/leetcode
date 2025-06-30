class Solution {
    void helper(int idx, vector<int>& arr, int target, set<vector<int>>& s, vector<int>& ds) {
        if (target == 0) {
            s.insert(ds);
            return;
        }

        for (int i = idx; i < arr.size(); ++i) {
            if (i > idx && arr[i] == arr[i - 1]) continue; // ✅ skip duplicate at same level
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            helper(i + 1, arr, target - arr[i], s, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to enable skipping
        set<vector<int>> s;
        vector<int> ds;
        helper(0, candidates, target, s, ds);
        return vector<vector<int>>(s.begin(), s.end());
    }
};
