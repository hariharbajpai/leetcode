class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;  // Sum of first `i` cards from the left
        int rsum = 0;   // Sum of first `k-i` cards from the right
        int totalsum = 0;
        int n = cardPoints.size();

        // Initialize lsum to take all `k` cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        totalsum = lsum;

        // Now, slide the window: take (k-i) from left and `i` from right
        int rightindex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];       // Remove the i-th left card
            rsum += cardPoints[rightindex]; // Add a right card
            rightindex--;

            // Update totalsum with the best possible combination
            totalsum = max(totalsum, lsum + rsum);
        }

        return totalsum;
    }
};