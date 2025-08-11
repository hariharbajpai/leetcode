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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> temp;
        ListNode* curr = head;

        // dump values
        while (curr != nullptr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        if (temp.empty()) return nullptr;

        // remove nth from end => index = len - n
        int len = (int)temp.size();
        int idx = len - n;
        if (idx >= 0 && idx < len) {
            temp.erase(temp.begin() + idx);
        }

        if (temp.empty()) return nullptr;

        // rebuild
        ListNode* newlist = new ListNode(temp[0]);
        ListNode* Nxt = newlist;

        for (int i = 1; i < (int)temp.size(); i++) {
            Nxt->next = new ListNode(temp[i]);
            Nxt = Nxt->next;
        }
        return newlist;
    }
};
