class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
           ListNode* head = NULL;
        
           if(list1 && list2){
               if(list1->val < list2->val){
                   head = list1;
                   list1 = list1->next;
               }
               else{
                   head = list2;
                   list2 = list2->next;
               }
           }
           else if(list1){
               head = list1;
               list1 = list1->next;
           }
           else if(list2){
               head = list2;
               list2 = list2->next;
           }
           else return head;
        
           ListNode* node = head;
        
           while(list1 && list2){
               
                 if(list1->val > list2->val){
                       head->next = list2;
                       list2 = list2->next;
                 }
                 else{
                        head->next = list1;
                        list1 = list1->next;
                 }

                 head = head->next;
           }
        
           while(list1){
               head->next = list1;
               list1 = list1->next;
               head = head->next;
           }
        
           while(list2){
               head->next = list2;
               list2 = list2->next;
               head = head->next;
           }
        
        return node;
    }
};