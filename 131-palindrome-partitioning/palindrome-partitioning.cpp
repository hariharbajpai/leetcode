class Solution {
    void helper(int idx, string &s, vector<string> &path, vector<vector<string>> &ans) {
        if (idx == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));  // pick
                helper(i + 1, s, path, ans);
                path.pop_back();  // backtrack
            }
        }
    }

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0, s, path, ans);
        return ans;
    }
};
