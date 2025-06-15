class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m1 , m2;

        for(int i : arr){
            m1[i]++;
        }
        for(auto i : m1){
            if(m2.find(i.second) != m2.end()) return false;
            m2[i.second]++;
        }
        return true;
    }
};