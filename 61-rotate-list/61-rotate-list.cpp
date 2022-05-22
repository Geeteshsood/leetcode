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
    
    int findlength(ListNode* head){
        
        int len = 0;
        
        while(head){
            head = head->next;
            len++;
        }
        
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)return head;
        
        int len = findlength(head);
        
        k = k%len;
        
        if(k == 0)return head;
        
        ListNode* nex = head , *cur = head;
        
        for(int i=0;i<k;i++){
            nex = nex->next;
        }
        
        while(nex && nex->next){
            cur = cur->next;
            nex = nex->next;
        }
        
        ListNode* node = cur->next;
        
        nex->next = head;
        cur->next = NULL;
        
        return node;
    }
};