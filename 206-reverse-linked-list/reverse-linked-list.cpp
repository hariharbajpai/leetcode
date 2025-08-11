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
    ListNode* reverseList(ListNode* head) {
        vector<int>temp;
        ListNode* curr = head;

        while(curr!=nullptr){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        if(temp.empty()) return nullptr;
        reverse(temp.begin(),temp.end());

        ListNode* newlist = new ListNode(temp[0]);
        ListNode* Nxt = newlist;
        
        for(int i = 1; i < temp.size(); i++){  
            Nxt->next = new ListNode(temp[i]);  
            Nxt = Nxt->next;
        }
        
        return newlist;
    }
};