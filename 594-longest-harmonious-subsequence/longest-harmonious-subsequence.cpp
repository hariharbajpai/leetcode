class Solution {
public:
    int findLHS(vector<int>& nums) {
        int l =0,r=0,maxlen = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        while(r<n){
        if(nums[r]-nums[l]==1){
            int  len = r-l+1;
            maxlen = max(maxlen,len);
            r++;
        }else if(nums[l]==nums[r]) {
            r++;
          }else{
            l++;
          }
        }
        return maxlen;
    }
};