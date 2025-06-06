class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int> result;


        for(int i : nums1){
            mp[i]++;
        }
        for(int i : nums2){
            if(mp.find(i)!=mp.end() && mp[i]>0 ){
                result.push_back(i);
                mp[i]--;
                
            }
        }
        return result;
    }
};
