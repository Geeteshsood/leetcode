class Solution {
public:
    
    bool find(TreeNode* root1,TreeNode* root2){
        
       if(!root1 || !root2)return root1 == root2;
       
       if(root1->val != root2->val)return false;
        
       int left = find(root1->left,root2->right);
       int right = find(root1->right,root2->left);
        
       return left && right;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return find(root,root);
    }
};