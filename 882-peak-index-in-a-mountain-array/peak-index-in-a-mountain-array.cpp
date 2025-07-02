class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2; // start from 1 and end at n-2 to avoid out-of-bound
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; // peak
            } else if (arr[mid] < arr[mid + 1]) {
                l = mid + 1; // move right
            } else {
                r = mid - 1; // move left
            }
        }
        return -1; // theoretically unreachable for valid mountain arrays
    }
};
