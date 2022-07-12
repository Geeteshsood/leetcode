class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
       ListNode* temp = NULL , *node = NULL;  
        
       if(!l1 && !l2)return NULL;
       else if(l1 && l2==NULL)return l1; 
       else if(l1==NULL && l2)return l2;

        
       while(l1!=NULL && l2!=NULL){
         
          if(l1->val<l2->val){
               if(temp == NULL){
                 temp = l1;
                 node = l1;
                 l1 = l1->next;
               }
               else{
                 temp->next = l1;
                 temp = l1;
                 l1 = l1->next;
               }    
          }
          else{
              if(temp == NULL){
                 temp = l2;
                 node = l2;
                 l2 = l2->next;
              }
              else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
              }    
          }
       }  
        
       while(l1){
         temp->next = l1;
         temp = l1;
         l1 = l1->next;
       }
       
       while(l2){
         temp->next = l2;
         temp = l2;
         l2 = l2->next;
       } 
        
     return node;   
    }
    
    ListNode* merge(int start,int end,vector<ListNode*> &lists){
        
        if(start > end)return NULL;
        else if(start == end){
            return lists[start];
        }
        
        int mid = start + (end - start)/2;
        
        ListNode* l1 = merge(start,mid,lists);
        ListNode* l2 = merge(mid+1,end,lists);
        
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        return merge(0,k-1,lists);
        
    }
};