/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
             if(head == NULL)return head;
        
             ListNode* node = head;
        
             for(int i=0;i<k-1;i++){
                 node = node->next;
                 if(node == NULL)return head;
             }
         
             ListNode* nex = node->next;
             node->next = NULL;
               
             ListNode* temp1 = reverseList(head);
             ListNode* temp2 = reverseKGroup(nex,k);
        
             head->next = temp2;
        
        return temp1;
    }
};