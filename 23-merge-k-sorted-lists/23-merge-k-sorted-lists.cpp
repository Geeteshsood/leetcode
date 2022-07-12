class Solution {
public:
    typedef pair<int,ListNode*> pi;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        ListNode* pre = NULL , *head = NULL;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(int i=0;i<k;i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        
        while(pq.size()){
            
            ListNode* node = pq.top().second;
            
            pq.pop();
            
            if(node->next)pq.push({node->next->val,node->next});
            
            if(head == NULL){
                head = node;
                pre =  node;
            }
            else {
                pre->next = node;
                pre = pre->next;
            }
            
        }
        
        return head;
    }
};