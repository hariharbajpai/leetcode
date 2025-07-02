class Solution {
  public:
    pair<long, long> indexes(vector<long long> v, long long x) {
        long long n = v.size();
        long long l = 0, r = n - 1;
        long long left_idx = -1, right_idx = -1;

        // Find leftmost index
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (v[mid] == x) {
                left_idx = mid;
                r = mid - 1;  // go left
            } else if (v[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // Find rightmost index
        l = 0, r = n - 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (v[mid] == x) {
                right_idx = mid;
                l = mid + 1;  // go right
            } else if (v[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {left_idx, right_idx};
    }
};
