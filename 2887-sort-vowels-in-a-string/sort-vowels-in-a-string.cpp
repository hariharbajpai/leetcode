class Solution {
public:
    string sortVowels(string s) {
        vector<int> upper(26, 0);   
        vector<int> lower(26, 0);   

        // First pass: Count vowels and mark them with '#'
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                lower[c - 'a']++;
                s[i] = '#';
            }
            else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                upper[c - 'A']++;
                s[i] = '#';
            }
        }

        // Collect sorted vowels
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

        // Replace '#' with sorted vowels
        int first = 0, second = 0;
        while(first < s.size() && second < vowels.size()) {
            if(s[first] == '#') {
                s[first] = vowels[second];
                second++;
            }
            first++;
        }

        return s;
    }
};
