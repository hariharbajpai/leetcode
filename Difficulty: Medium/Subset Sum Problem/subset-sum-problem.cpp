class Solution {
    bool helper(int idx, vector<int>& arr, int sum) {
        // Base Case: target achieved
        if (sum == 0) return true;

        // Base Case: end of array
        if (idx == arr.size()) return false;

        // Pick current element if it's not greater than target
        if (arr[idx] <= sum) {
            if (helper(idx + 1, arr, sum - arr[idx])) return true;
        }

        // Not pick current element
        if (helper(idx + 1, arr, sum)) return true;

        return false;
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        return helper(0, arr, sum);
    }
};
