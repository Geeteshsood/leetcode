class Solution {
public:
    
    int camera = 0;
    
    int dfs(TreeNode* root){
        
        if(root == NULL)return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == -1 || right == -1){
            camera++;
            return 1;
        }
        else if(left == 1 || right == 1){
            return 0;
        }
        
      return -1;  
    }
    
    int minCameraCover(TreeNode* root) {
        
        int val = dfs(root);
        
        if(val == -1)camera++;
        
        return camera;
    }
};