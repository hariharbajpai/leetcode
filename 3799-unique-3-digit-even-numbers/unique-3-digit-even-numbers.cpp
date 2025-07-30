class Solution {
    void helper(vector<int>& digits, vector<bool>& used, vector<int>& temp, set<int>& result) {
        if (temp.size() == 3) {
            if (temp[0] == 0) return;           // no leading 0
            if (temp[2] % 2 != 0) return;       // must end with even digit

            int num = temp[0] * 100 + temp[1] * 10 + temp[2];
            result.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); ++i) {
            if (used[i]) continue;             // already picked this digit

            // Pick
            used[i] = true;
            temp.push_back(digits[i]);
            helper(digits, used, temp, result);
            
            // Not Pick (Backtrack)
            used[i] = false;
            temp.pop_back();
        }
    }

public:
    int totalNumbers(vector<int>& digits) {
        set<int> result;
        vector<bool> used(digits.size(), false);
        vector<int> temp;

        helper(digits, used, temp, result);
        return result.size();
    }
};
