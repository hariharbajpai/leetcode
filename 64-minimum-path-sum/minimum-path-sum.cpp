class Solution {
    int helper(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r == 0 && c == 0) return grid[0][0];
        if (r < 0 || c < 0) return INT_MAX;

        if (dp[r][c] != -1) return dp[r][c];

        int up = helper(r - 1, c, grid, dp);
        int left = helper(r, c - 1, grid, dp);

        return dp[r][c] = grid[r][c] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> dp(r, vector<int>(c, -1));
        return helper(r - 1, c - 1, grid, dp);
    }
};
