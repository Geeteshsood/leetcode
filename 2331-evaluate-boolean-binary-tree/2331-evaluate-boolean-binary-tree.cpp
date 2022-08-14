/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool dfs(TreeNode* root){
        
        if(root == NULL)return false;
        
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        
        if(!root->left && !root->right)return root->val;
        
        if(root->val == 3){
            return left & right;
        }
        else if(root->val == 2){
            return left | right;
        }
        
      return false;  
    }
    
    bool evaluateTree(TreeNode* root) {
        
       return dfs(root);
 
    }
};