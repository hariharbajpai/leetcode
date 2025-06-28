class Solution {
public:
    string sortVowels(string s) {
        vector<int> upper(26, 0);   
        vector<int> lower(26, 0);   

    
        for(char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                lower[c-'a']++;
            }
            else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                upper[c-'A']++;
            }
        }

        string vowels;
         
        for(int i = 0; i < 26; i++) {
            char c = 'A' + i;
            while(upper[i] > 0) {
                vowels += c;
                upper[i]--;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while(lower[i] > 0) {
                vowels += c;
                lower[i]--;
            }
        }

         
        int vowel_idx = 0;
        for(char &c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                c = vowels[vowel_idx++];
            }
        }

        return s;
    }
};