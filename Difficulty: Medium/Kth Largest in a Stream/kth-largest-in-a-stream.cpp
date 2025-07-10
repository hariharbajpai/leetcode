class Solution {
public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < n; ++i) {
            if (minHeap.size() < k) {
                minHeap.push(arr[i]);
            } else {
                if (arr[i] > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }
            
            if (minHeap.size() >= k) {
                result.push_back(minHeap.top());
            } else {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};