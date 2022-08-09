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
    vector<int> preorderTraversal(TreeNode* root) {
              
        stack<TreeNode*> st;
        vector<int> res;
        if(root)st.push(root);
        
        while(st.size()){
            
          TreeNode* node = st.top();
          st.pop();
            
          res.push_back(node->val);
          if(node->right)st.push(node->right);
            
          while(node->left){
              node = node->left;
              if(node->right)st.push(node->right);
              res.push_back(node->val);
          }
            
        }
        
        return res;
        
    }
};