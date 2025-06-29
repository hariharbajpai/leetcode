class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(char c : ransomNote){
            mp1[c]++;
        }
        for(char c : magazine){
            mp2[c]++;
        }

         for (auto& pair : mp1) {
            char c = pair.first;
            int count = pair.second;
            
            if (mp2[c] < count) {
                return false;
            }
        }

        return true;
    }
};