class Solution {
public:
    
    ListNode* node = NULL;
    
    ListNode* reverse(ListNode* head){
        
         if(head->next == NULL){
            node = head;
            return head;
        }
        
        ListNode* temp = reverse(head->next);
        temp->next = head;
        head->next = NULL;
        
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        
         if(head)reverse(head);
        
        return node;
    }
};