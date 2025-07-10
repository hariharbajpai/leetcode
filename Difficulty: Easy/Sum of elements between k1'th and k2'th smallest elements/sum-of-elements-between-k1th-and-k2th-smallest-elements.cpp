class Solution {
public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        
        sort(A, A + N);
        
        long long sum = 0;
        
        
        for (long long i = K1; i < K2 - 1; ++i) {
            sum += A[i];
        }
        
        return sum;
    }
};