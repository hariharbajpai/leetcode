class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n =  score.size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++) ans.push_back({score[i],i});
        sort(ans.rbegin(),ans.rend());

        vector<string>res(n);
        for(int i =0;i<n;i++){
            if(i==0) res[ans[i].second] = "Gold Medal";
            else if(i==1) res[ans[i].second] = "Silver Medal";
            else if(i==2) res[ans[i].second] = "Bronze Medal";
            else res[ans[i].second] = to_string(i+1);
        }
        return res;
    }
};