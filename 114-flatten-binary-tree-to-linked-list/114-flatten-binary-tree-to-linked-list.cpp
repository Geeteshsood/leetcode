class Solution {
public:
    TreeNode* prev = NULL;
    
     void dfs(TreeNode* root){
        
        if(root == NULL)return ;
        
        dfs(root->right);
        dfs(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        
         dfs(root);

    }
};