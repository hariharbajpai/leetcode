class Solution {
public:
    // Helper function with memoization
    bool helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;              // Subset found
        if (idx < 0) return false;                 // No elements left

        if (dp[idx][target] != -1) return dp[idx][target];

        bool notpick = helper(idx - 1, target, nums, dp);
        bool pick = false;
        if (target >= nums[idx])
            pick = helper(idx - 1, target - nums[idx], nums, dp);

        return dp[idx][target] = pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        int n = nums.size();
        // DP: n x (target+1)
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(n - 1, target, nums, dp);
    }
};
