class Solution {
  public:
    int findSubString(string str) {
    unordered_set<char> unique_chars(str.begin(), str.end()); // step 1
    int total_unique = unique_chars.size();

    unordered_map<char, int> window_freq;
    int i = 0, j = 0, n = str.size();
    int min_len = INT_MAX;
    int count = 0;

    while (j < n) {
        window_freq[str[j]]++;
        if (window_freq[str[j]] == 1) {
            count++;
        }

        // Try to shrink the window
        while (count == total_unique) {
            min_len = min(min_len, j - i + 1);
            window_freq[str[i]]--;
            if (window_freq[str[i]] == 0) {
                count--;
            }
            i++;
        }

        j++;
    }

    return min_len;
}
};