class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[eggs][moves] = max floors you can check with 'eggs' eggs and 'moves' drops
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        
        int m = 0;
        while (dp[k][m] < n) {
            m++;
            for (int egg = 1; egg <= k; egg++) {
                dp[egg][m] = dp[egg][m - 1] + dp[egg - 1][m - 1] + 1;
            }
        }
        return m;
    }
};