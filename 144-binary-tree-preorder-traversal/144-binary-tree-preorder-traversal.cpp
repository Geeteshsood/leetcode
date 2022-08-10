class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* cur = root;
        
        while(cur){
            
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                
               TreeNode* pre = cur->left;
                   
               while(pre->right != NULL && pre->right != cur){
                   pre = pre->right;
               }
               
               if(pre->right == NULL){
                   ans.push_back(cur->val);
                   pre->right = cur;
                   cur = cur->left;
               }
               else{
                   pre->right = NULL;
                   cur = cur->right;
               }
                   
            }
        }
        
     return ans;
    }
};