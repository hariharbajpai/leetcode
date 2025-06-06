class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        vector<int> result;
        
        
        for (int num : nums1) {
            mp1[num]++;
        }
        
      
        for (int num : nums2) {
            if (mp1.find(num) != mp1.end() && mp1[num] > 0) {
                result.push_back(num);
                mp1[num] = 0;  
            }
        }
        
        return result;
    }
};