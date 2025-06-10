class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> temp;
        int n = nums.size();

        for(int i : nums){
            mp[i]++;
        }
        for(auto pair :mp){
            if(pair.second > n/3) {
                temp.push_back(pair.first);
            }
        }
        return temp;
    }
};