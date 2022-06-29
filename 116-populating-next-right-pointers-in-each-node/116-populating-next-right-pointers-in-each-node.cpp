class Solution {
public:
    
    Node* connect(Node* root) {
        
        queue<Node*> q;
        if(root)q.push(root);
        
        while(q.size()){
            
            int size = q.size();
            Node* prev = NULL;
            
            for(int i=0;i<size;i++){
                
                Node* cur = q.front();
                q.pop();
                
                if(i != 0){
                    prev->next = cur;
                }
            
                if(i == size-1){
                    cur->next = NULL;
                }
                
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                    
                prev = cur;
            }
            
        }
        
     return root;
    }
};