class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* cur = root;
        
        while(cur){
            
          if(cur->left == NULL){
              cur = cur->right;
          }
          else{
              
              TreeNode* pre = cur->left;
              
              while(pre->right != NULL){
                  pre = pre->right;
              }

              if(pre->right == NULL){
                  pre->right = cur->right;
                  cur->right = cur->left;
                  cur->left = NULL;
              }
              
              cur = cur->right;
          }  
            
        }

    }
};