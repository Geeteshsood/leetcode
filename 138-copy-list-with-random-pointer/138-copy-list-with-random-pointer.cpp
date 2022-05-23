class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)return head;
        
        Node* nex = head , *node = NULL ;
        
        while(nex){
           
           node = nex;
           nex = nex->next;
            
           Node* temp = new Node(node->val);
           temp->next = node->next;
           node->next = temp;
        }

        node = head;
        
        while(node){
            
           Node* temp = node->random;
            
           if(temp){
               node->next->random = temp->next;
           }
           else node->next->random = NULL;
            
           node = node->next->next;
            
        }

        Node* pre = head , *cur = head->next , *start = head->next;
        
        while(cur){
            
           pre->next = cur->next;
           pre = cur;
           cur = cur->next;
            
        }
        
     return start;
    }
};