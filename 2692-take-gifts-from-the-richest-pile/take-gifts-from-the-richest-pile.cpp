class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {   
         
        priority_queue<int> pq(gifts.begin(), gifts.end());

        
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            
            int maxGifts = pq.top();
            pq.pop();
            int newGifts = floor(sqrt(maxGifts));
            pq.push(newGifts);
        }

       
        long long total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};