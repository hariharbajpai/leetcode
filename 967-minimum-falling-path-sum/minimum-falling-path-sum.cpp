class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: first row is same
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Build DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int left = matrix[i][j] + (j > 0 ? dp[i - 1][j - 1] : 1e9);
                int right = matrix[i][j] + (j < n - 1 ? dp[i - 1][j + 1] : 1e9);

                dp[i][j] = min({up, left, right});
            }
        }

        // Final answer: minimum in last row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};
