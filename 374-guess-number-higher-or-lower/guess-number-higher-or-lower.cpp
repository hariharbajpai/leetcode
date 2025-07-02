/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// The guess API is defined for you.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int res = guess(mid); // uses given API

            if (res == 0) return mid;      // correct guess
            else if (res < 0) r = mid - 1; // too high
            else l = mid + 1;              // too low
        }

        return -1; // edge case (won’t be hit if number exists)
    }
};
