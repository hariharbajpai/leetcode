class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());

        for(int i=0;i<k-1;i++){
            if(!pq.empty()) pq.pop();
        }

        return pq.empty() ? -1 : pq.top();
    }
};