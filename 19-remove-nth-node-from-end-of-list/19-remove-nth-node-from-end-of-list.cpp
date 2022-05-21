class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* cur = head , *nex = head;
        
        for(int i=0;i<n;i++){
            nex = nex->next;
        }
        
        if(nex == NULL)return head->next;
        
        while(nex && nex->next){
            cur = cur->next;
            nex = nex->next;
        }
        
        cur->next = cur->next->next;
        
        return head;
    }
};