class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        ListNode* pre = NULL , *head = NULL;

        while(true){
            
            int idx = -1 , mini = INT_MAX;
            
            for(int i=0;i<k;i++){
                
                if(lists[i] == NULL)continue;
                
                int val = lists[i]->val;
                
                if(val < mini){
                    mini = val;
                    idx = i;
                }
                
            }
            
            if(idx == -1)break;
            
            if(head == NULL){
                head = lists[idx];
                pre =  lists[idx];
            }
            else {
                pre->next = lists[idx];
                pre = pre->next;
            }
            
            lists[idx] = lists[idx]->next;
        }
        
        return head;
    }
};