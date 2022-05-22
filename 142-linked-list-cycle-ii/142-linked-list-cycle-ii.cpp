class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head , *fast = head;
        
        bool cycle = false;
        
        while(fast && fast->next && !cycle){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                 cycle = true;
                 break;
            }
        }
        
        if(!cycle)return NULL;

        ListNode* start = head;
        
        while(start != slow){
            
            start = start->next;
            slow = slow->next;
            
        }
        
      return start;  
    }
};