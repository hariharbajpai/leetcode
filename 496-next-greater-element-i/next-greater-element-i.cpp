class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int ,int>mp;
         stack<int>st;
         for(int i : nums2){
            while(!st.empty() && i>st.top()){
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
         }
         vector<int>ans;
         for(int i : nums1){
            i = mp.count(i) ? mp[i] : -1;
            ans.push_back(i);
         }
            return ans;
    }
};