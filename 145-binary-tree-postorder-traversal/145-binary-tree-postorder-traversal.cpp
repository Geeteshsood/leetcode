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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st1,st2;
        
        if(root)st1.push(root);
        
        while(st1.size()){
            
            TreeNode* temp = st1.top();
            st1.pop();
            
            st2.push(temp);
            
            TreeNode* node = st2.top();
            
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
            
        }
        
        vector<int> res;
        
        while(st2.size()){
            
           int val = st2.top()->val;
           st2.pop();
            
           res.push_back(val);
            
        }
        
    return res;
    }
};