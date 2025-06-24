class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;
        int left = 0;
        unordered_map<int, int> fruitCount;
        
        for (int right = 0; right < fruits.size(); ++right) {
            fruitCount[fruits[right]]++;
            
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }
            
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};