class Solution {
  public:
    bool helper(int idx, int k, vector<int>& arr, int n) {
        if (k == 0) return true;
        if (idx == n) return false;

        
        if (arr[idx] <= k) {
            if (helper(idx + 1, k - arr[idx], arr, n)) return true;
        }

        
        return helper(idx + 1, k, arr, n);
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return helper(0, k, arr, n);
    }
};
