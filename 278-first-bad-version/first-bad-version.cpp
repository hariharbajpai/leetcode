// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,r =n;
        int mid =0;

        while(l<r){
            mid = l+(r-l)/2;
            bool res = isBadVersion(mid);
            if(res) r=  mid;
            else l = mid+1;
        }
        return l;
    }
};