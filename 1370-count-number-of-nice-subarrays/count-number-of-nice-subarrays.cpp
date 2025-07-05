class Solution {
    int atmost(vector<int>&nums,int k){
        int r=0,l=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum += nums[r]%2;
            while(sum>k){
                sum -= nums[l]%2;
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atmost(nums,k) -atmost(nums,k-1);
    }
};