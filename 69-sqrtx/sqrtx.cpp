class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int l =0,r =  x-1;
        int ans = -1;

        while(l<=r){
        long long mid = l+(r-l)/2;
            long long square = mid*mid;
            if(square==x) return mid;
            if(square<x){
                ans = mid;
                l = mid+1;
            }else r = mid-1;
        }
        return ans;
    }
};