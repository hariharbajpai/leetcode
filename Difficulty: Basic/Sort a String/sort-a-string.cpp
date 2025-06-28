string sort(string s) {
    // complete the function here
    vector<int>alpha(26,0);
    
    for(char c : s){
        int index = c - 'a';
        alpha[index]++;
    }
    string ans;
  for(int i = 0; i < 26; i++) {   
        char c = 'a' + i;           
        while(alpha[i] > 0) {       
            ans += c;
            alpha[i]--;
        }
    }
    return ans;
}