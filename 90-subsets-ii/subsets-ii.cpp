class Solution {
    void helper(int idx , vector<int>& arr, set<vector<int>>& unique, vector<int>& ds){
        if(idx == arr.size()){
            unique.insert(ds); // only unique subsets will be added
            return;
        }

        // pick
        ds.push_back(arr[idx]);
        helper(idx + 1, arr, unique, ds);
        ds.pop_back();

        // not pick
        helper(idx + 1, arr, unique, ds);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sorting ensures set works properly
        set<vector<int>> unique;
        vector<int> ds;

        helper(0, nums, unique, ds);

        return vector<vector<int>>(unique.begin(), unique.end());
    }
};
