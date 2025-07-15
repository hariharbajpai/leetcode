class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // code here
        if(s1.size()!=s2.size()) return false;
        vector<int> freq(26,0);
        for(char c : s1){
            freq[c-'a']++;
        }
        for(char c : s2){
           if(freq[c-'a'] > 0) freq[c-'a']--;
        }
        int change = 0;
        for(int x : freq){
            change += x;
        }
        return change <=k;
        
    }
};