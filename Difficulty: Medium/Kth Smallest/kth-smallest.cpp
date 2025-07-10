class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        // Pop (k-1) elements to reach the kth smallest
        for (int i = 0; i < k - 1; i++) {
            if (!pq.empty()) {
                pq.pop();
            }
        }
        
        // The top now is the kth smallest
        return pq.empty() ? -1 : pq.top();  
    }
};