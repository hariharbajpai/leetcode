// User function Template for C++

class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>res = a;
        
        res.insert(res.end(),b.begin(),b.end());
        make_heap(res.begin(),res.end());
        
        return res;
        
       
    }
};
