class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        if(root)q.push(root);
        
        while(q.size()){
            
            int size = q.size();
            
            for(int k=0;k<size;k++){
                
                TreeNode* node = q.front();
                q.pop();
                
                swap(node->left,node->right);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            
        }
        
        return root;
    }
};