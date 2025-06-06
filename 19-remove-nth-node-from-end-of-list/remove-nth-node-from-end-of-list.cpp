class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        
        ListNode* curr = head;
        int length = 0;
        
   
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
    
        int position = length - n;
        curr = head;
        ListNode* prev = nullptr;
         
        for (int i = 0; i < position; i++) {
            prev = curr;
            curr = curr->next;
        }
        
         
        if (prev == nullptr) {
            
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        
        return head;
    }
};