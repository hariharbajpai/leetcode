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

        // 1) Dump values
        ListNode* curr = head;
            vector<int> temp;
        while (curr != nullptr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        // 2) Reorder sequence: L0, Ln, L1, Ln-1, ...
        vector<int> order;
        int i = 0, j = (int)temp.size() - 1;
        while (i <= j) {
            if (i == j) {
                order.push_back(temp[i]);
            } else {
                order.push_back(temp[i]);
                order.push_back(temp[j]);
            }
            ++i; --j;
        }

        // 3) Write back into the SAME list (void signature ⇒ in-place)
        curr = head;
        int k = 0;
        while (curr != nullptr) {
            curr->val = order[k++];
            curr = curr->next;
        }
    }
};
