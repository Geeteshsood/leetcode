class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
             int len1 = 0 , len2 = 0;
        
             ListNode* temp1 = headA , *temp2 = headB;
        
             while(temp1){
                 len1++;
                 temp1 = temp1->next;
             }
        
             while(temp2){
                 len2++;
                 temp2 = temp2->next;
             }
        
             if(len1 > len2){
                 for(int i=0;i<len1-len2;i++)headA = headA->next;
             }
             else for(int i=0;i<len2-len1;i++)headB = headB->next;
     
             while(headA != headB && headA && headB){
                   headA = headA->next;
                   headB = headB->next;
             }
        
        
      return headA;
    }
};