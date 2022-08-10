class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;
        if(root)q.push(root);
        
        while(q.size()){
            
            int size = q.size();
            Node* pre = NULL;
            
            for(int g=0;g<size;g++){
                
                Node* cur = q.front();
                q.pop();
                
                if(pre ==  NULL){
                    pre = cur;
                }
                else{
                    pre->next = cur;
                    pre = pre->next;
                }
                
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            
           pre->next = NULL;
        }
        
       return root; 
    }
};