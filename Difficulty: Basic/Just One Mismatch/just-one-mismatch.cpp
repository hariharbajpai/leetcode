class Solution {
  public:
    string isStringExist(vector<string> arr, int N, string S) {
        // code here
        for(auto word : arr ){
            if(word.size() != S.size()) continue;
            int cnt = 0;
            for(int i =0;i<S.size();i++){
                if(word[i] != S[i]) cnt++;
                if(cnt>1) break;
                
            }
                if(cnt == 1) return "True";
        }
        return "False";
    }
};