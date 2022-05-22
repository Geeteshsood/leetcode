class Solution {
public:
    
    bool isPalindrome(ListNode* head) {
        
        bool even = false;
        
        ListNode* pre = NULL , *cur = NULL;
        ListNode* slow = head , *fast = head;
        
        while(fast && fast->next){
            
            fast = fast->next->next;
            
            if(fast == NULL)even = true;
            
            cur = slow;
            slow = slow->next;
            cur->next = pre;
            pre = cur;
        
        }
        
        ListNode * nex = NULL;
        
        if(even)nex = slow;
        else nex = slow->next;
        
        while(pre){
           if(pre->val != nex->val){
               return false;
           }
           pre = pre->next;
           nex = nex->next;
        }
        
      return true;  
    }
};