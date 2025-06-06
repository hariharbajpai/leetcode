#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0;
        long long maxi = 0;
        int i = 0;
        int n = nums.size();
        
        for (int j = 0; j < n; ++j) {
            freq[nums[j]]++;
            sum += nums[j];
            
            // If the window size exceeds k, move the left pointer
            while (j - i + 1 > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
            }
            
            // If the window size is exactly k and all elements are distinct
            if (j - i + 1 == k && freq.size() == k) {
                maxi = max(maxi, sum);
            }
        }
        
        return maxi;
    }
};