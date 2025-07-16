class Solution {
    int f(int idx , vector<int>&dp){
        if(idx<0) return 0;
        if(idx==0) return 1;
        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = f(idx-2,dp) + f(idx-1,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};