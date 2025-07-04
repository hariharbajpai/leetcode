class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0,a=-1,b=-1,c=-1,i=0;
        int n=s.size(),minWindow=0;
        while(i<n){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            
            if(a!=-1 && b!=-1 && c!=-1){
                minWindow=min(min(a,b),c)+1;
                count+=minWindow;
            }
            i++;
        }
        return count;
    }
};