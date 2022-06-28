class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       
        vector<int> inorder;
        
        TreeNode* cur = root;
        
        while(cur){
            
          if(cur->left == NULL){
              inorder.push_back(cur->val);
              cur = cur->right;
          }
          else{
              
              TreeNode* pre = cur->left;
              
              while(pre->right != NULL && pre->right != cur){
                  pre = pre->right;
              }

              if(pre->right == NULL){
                  pre->right = cur;
                  cur = cur->left;
              }
              else{
                  pre->right = NULL;
                  inorder.push_back(cur->val);
                  cur = cur->right;
              }
          }  
            
        }
        
     return inorder;
    }
};