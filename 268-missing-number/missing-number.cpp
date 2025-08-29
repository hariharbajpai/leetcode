class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int Tsum = n*(n+1)/2;

        for(int i : nums){
            sum += i;
        }
        int ans = Tsum-sum;
        return ans;
    }
};