class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_with_index;
        for (int i = 0; i < nums.size(); i++) {
            num_with_index.push_back({nums[i], i});  
        }

     
        sort(num_with_index.begin(), num_with_index.end());

        int s = 0;
        int l = nums.size() - 1;
        vector<int> temp;

        while (s < l) {
            int sum = num_with_index[s].first + num_with_index[l].first;
            if (sum == target) {
                temp.push_back(num_with_index[s].second);
                temp.push_back(num_with_index[l].second);
                break;  
            }
            else if (sum > target) {
                l--;
            }
            else {
                s++;
            }
        }

        return temp;  
    }
};
