class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = NULL;
        
        if(list1 && list2){
            if(list1->val > list2->val)swap(list1,list2);
            head = list1;
        }
        else if(list1)return list1;
        else if(list2)return list2;
        else return NULL;
        
        while(list1 && list2){
            
            ListNode* temp = NULL;
            
            while(list1 && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            
            temp->next = list2;
            swap(list1,list2);
        }
        
        return head;
    }
};