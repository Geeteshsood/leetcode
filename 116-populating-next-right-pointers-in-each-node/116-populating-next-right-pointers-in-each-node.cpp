class Solution {
public:
    
    Node* connect(Node* root) {
        
        Node* cur = root;
        
        while(cur){
            
           Node* temp = cur , *nex = NULL;
               
           while(cur != NULL && cur->left != NULL){
              
              if(nex != NULL){
                  nex->next = cur->left;
                  nex = nex->next;
              }
              else nex = cur->left;
               
              nex->next = cur->right;
              nex = nex->next;
              cur = cur->next;
           }
         
           if(nex)nex->next = NULL;
           cur = temp->left;
        }
        
        return root;
    }
};