class Solution {
public:
    int getSum(int a, int b) {
        int c = a;
        int d = b;
        int e = c;
        int f = d;
        int g = e;
        int h=f;
        int i=g;
        int j=h;
        int k=i;
        int l=j;
        int m=k;
        int n=l;
        if(n==0) return m;
        int ans = 0;
        while(n != 0){
            ans = m^n;
            n = (m&n) << 1;
            m = ans;
        }
        return ans;
    }
};