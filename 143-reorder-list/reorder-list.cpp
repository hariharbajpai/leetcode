/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        vector<int> temp;
        ListNode* curr = head;

        while (curr != nullptr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }
        
        int l = 0;
        int r = temp.size() - 1;
        vector<int> ans;
        
       
        while (l <= r) {
            if (l == r) {
                ans.push_back(temp[l]);
            } else {
                ans.push_back(temp[l]);
                ans.push_back(temp[r]);
            }
            l++;
            r--;
        }
        
         
        curr = head;
        for (int val : ans) {
            curr->val = val;
            curr = curr->next;
        }
    }
};