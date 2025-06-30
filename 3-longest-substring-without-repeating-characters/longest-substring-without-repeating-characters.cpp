class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l =0,r=0,maxlen=0;
        
        while(r<s.size()){
            if(mp.find(s[r])!=mp.end() && mp[s[r]] >= l){
                l = mp[s[r]]+1;
            }
            mp[s[r]] = r;
            int len = r-l+1;
            maxlen = max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};