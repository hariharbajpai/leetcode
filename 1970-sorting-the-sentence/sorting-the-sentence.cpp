class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);   
        string temp;
        int index = 0;

        while(index < s.size()) {
            if(s[index] == ' ') {
                int pos = temp.back() - '0';  
                temp.pop_back();               
                ans[pos] = temp;               
                temp.clear();                  
                index++;                       
            }
            else {
                temp += s[index];
                index++;
            }
        }

        // Process the last word (no space after it)
        if(!temp.empty()) {
            int pos = temp.back() - '0';
            temp.pop_back();
            ans[pos] = temp;
        }

        // Build the final sentence
        string result;
        for(const string& word : ans) {
            if(!word.empty()) {
                if(!result.empty()) result += " ";
                result += word;
            }
        }

        return result;
    }
};