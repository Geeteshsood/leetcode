class Solution {
public:
    
    TreeNode* dfs(TreeNode* root){
        
        if(root == NULL)return root;
        
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        
        root->right = left;
        root->left = right;
        
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        return dfs(root);
        
    }
};