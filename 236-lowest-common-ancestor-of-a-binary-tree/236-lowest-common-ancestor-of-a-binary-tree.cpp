/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        
        if(root == NULL || root == p || root == q)return root;
        
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
         
        if(left && right)return root;
        else if(left)return left;
        else if(right)return right;
      
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lca(root,p,q);
    }
};