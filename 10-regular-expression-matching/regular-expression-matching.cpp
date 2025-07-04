class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j] = true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;

        // Fill dp table for empty string but with patterns like "a*", "c*b*" etc.
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // Use zero occurrence of preceding char
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Two options with '*':
                    // 1. Zero occurrences of preceding char
                    dp[i][j] = dp[i][j - 2];

                    // 2. One or more occurrences, only if preceding char matches
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                // Else, remains false
            }
        }

        return dp[m][n];
    }
};