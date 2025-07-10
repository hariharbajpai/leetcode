#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {  // Change return type to long long
        // Create a max-heap from the gifts
        priority_queue<int> pq(gifts.begin(), gifts.end());

        // Perform k operations
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            
            int maxGifts = pq.top();
            pq.pop();
            int newGifts = floor(sqrt(maxGifts));
            pq.push(newGifts);
        }

        // Calculate the total remaining gifts (use long long to prevent overflow)
        long long total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};