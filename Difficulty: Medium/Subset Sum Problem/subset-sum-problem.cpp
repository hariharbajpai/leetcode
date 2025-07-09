class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // DP table of size (n+1) x (sum+1)
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        // Initialization
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;  // Subset with sum 0 always exists (empty subset)
        }
        for (int j = 0; j <= sum; j++) {
            dp[0][j] = false;  // No elements => no way to make sum > 0
        }
        dp[0][0] = true;  // Edge case: sum=0 and arr is empty

        // Fill DP Table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};