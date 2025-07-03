class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<k){
            string t = "";
            for(int i =0;i<s.size();i++){
                t += char(s[i]+1);
            }
            s+=t;
        }
        return s[k-1];
    }
};