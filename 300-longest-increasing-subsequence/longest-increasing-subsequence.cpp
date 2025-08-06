#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> dp;  

    int helper(int idx, int prevIdx, const vector<int>& nums) {
        if (idx == n) return 0;

        int &res = dp[idx][prevIdx + 1];
        if (res != -1) return res;
     
        int notPick = helper(idx + 1, prevIdx, nums);

        int pick = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            pick = 1 + helper(idx + 1, idx, nums);
        }

        return res = max(pick, notPick);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        n = (int)nums.size();
        dp.assign(n, vector<int>(n + 1, -1));  
        return helper(0, -1, nums);
    }
};
