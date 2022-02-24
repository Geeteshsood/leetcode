class Solution {
public:
    
    TreeNode* merge(TreeNode* root1,TreeNode* root2){
        
        if(!root1 || !root2){
            if(root1)return root1;
            else return root2;
        }
        
        TreeNode* node = new TreeNode(root1->val + root2->val);
        
         node->left = merge(root1->left,root2->left);
        node->right = merge(root1->right,root2->right);
        
        return node;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return merge(root1,root2);
    }
};