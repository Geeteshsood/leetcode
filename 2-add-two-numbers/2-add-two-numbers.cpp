class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
            ListNode* dummy = new ListNode();
            ListNode* head = dummy;
        
            int carry = 0;
        
            while(l1 || l2 || carry){
                
                int sum = 0;
                
                if(l1){
                    sum += l1->val;
                    l1 = l1->next;
                }
                
                if(l2){
                    sum += l2->val;
                    l2 = l2->next;
                }
                
                sum += carry;
                
                carry = sum/10;
                int val = sum%10;
                
                ListNode* node = new ListNode(val);
                
                head->next = node;
                head = head->next;
            }
        
       return dummy->next;
    }
};