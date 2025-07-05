class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i : arr){
            mp[i]++;
        }
        int maxlucky = -1;
        for(auto i : mp){
            if(i.first == i.second){
                maxlucky = max(maxlucky , i.first);
            }
        }
        return maxlucky;
    }
};