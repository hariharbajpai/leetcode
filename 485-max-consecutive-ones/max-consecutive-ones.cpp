class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), maxlen = 0;
        while (r < n) {
            if (nums[r] == 1) {
                r++;                        
            } else {
                maxlen = max(maxlen, r - l);  
                r++;                        
                l = r;                      
            }
        }
        maxlen = max(maxlen, r - l);      
        return maxlen;
    }
};
