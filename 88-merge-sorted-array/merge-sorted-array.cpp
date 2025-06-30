class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int l1 = 0;
        int l2 = 0;

        while (l1 < m && l2 < n) {
            if (nums1[l1] < nums2[l2]) {
                temp.push_back(nums1[l1]);
                l1++;
            } else {
                temp.push_back(nums2[l2]);
                l2++;
            }
        }

        while (l1 < m) {
            temp.push_back(nums1[l1]);
            l1++;
        }

        while (l2 < n) {
            temp.push_back(nums2[l2]);
            l2++;
        }

        for (int i = 0; i < temp.size(); i++) {
            nums1[i] = temp[i];
        }
    }
};
