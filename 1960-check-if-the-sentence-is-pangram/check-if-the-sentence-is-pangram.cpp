class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>alpha(26,0);
        for(char c : sentence){
            int index = c - 'a';
            alpha[index] = 1;
        }
        for(int i = 0;i<26;i++){
            if(alpha[i]==0) return 0;
        }
        return 1;
    }
};