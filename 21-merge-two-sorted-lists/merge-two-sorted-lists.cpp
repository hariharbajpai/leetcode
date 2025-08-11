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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 =list1;
        ListNode* curr2 = list2;
        vector<int>temp;

        while(curr1!=nullptr){
            temp.push_back(curr1->val);
            curr1 = curr1->next;
        }
        while(curr2!=nullptr){
            temp.push_back(curr2->val);
            curr2 = curr2->next;
        }
    if (temp.empty()) return nullptr;
        sort(temp.begin(),temp.end());

        ListNode* newlist = new ListNode(temp[0]);
        ListNode*  Nxt = newlist;

        for(int i =1;i<temp.size();i++){
            Nxt->next = new ListNode(temp[i]);
            Nxt = Nxt->next;
        }
        return newlist;

    }
};