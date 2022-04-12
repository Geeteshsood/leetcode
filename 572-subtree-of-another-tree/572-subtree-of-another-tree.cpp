class Solution {
public:
    
    bool check(TreeNode* root,TreeNode* subRoot){
        
        if(root == NULL && subRoot == NULL)return true;
        else if(root == NULL || subRoot == NULL)return false;
        
        if(root->val != subRoot->val)return false;
        
        return check(root->left,subRoot->left) && check(root->right,subRoot->right);
    }
    
    bool find(TreeNode* root,TreeNode* subRoot){
        
        if(root == NULL)return false;
        
        if(check(root,subRoot))return true;
        
        return find(root->left,subRoot) || find(root->right , subRoot);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
          return find(root,subRoot);
    }
};