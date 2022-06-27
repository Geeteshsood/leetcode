class Solution {
public:
    
    int find(TreeNode* root,bool &flag){
        
        if(root == NULL)return 0;
        
        if(!flag)return 0;
        
        int lh = find(root->left,flag);
        int rh = find(root->right,flag);
        
        if(abs(rh - lh) > 1)return flag = false;
        
        return 1 + max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        
        bool flag = true;
        
        find(root,flag);
        
      return flag;  
    }
};