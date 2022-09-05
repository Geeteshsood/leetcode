class Solution {
public:
    
    ListNode* reverse(ListNode* &head,ListNode* &ans){
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode* node = reverse(head->next,ans);
        
        if(node == NULL){
            ans = head;
        }
        else node->next = head;
        
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* ans = NULL;
        reverse(head,ans);
        if(head)head->next = NULL;
        
        return ans;
    }
};