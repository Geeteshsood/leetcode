class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* pre = NULL , *cur = NULL , *nex = head;
        
        while(nex != NULL){
            
            cur = nex;
            nex = nex->next;
            cur->next = pre;
            pre = cur;
        }
        
      return pre;  
    }
};