class Solution {
public:
    
    int find(TreeNode* root,int &width){
        
        if(root == NULL)return 0;
        
        int left = find(root->left,width);
        int right = find(root->right,width);
        
        width = max(width,1 + left + right);
        
        return 1 + max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int width = 0;
        find(root,width);
    
        return width-1;
    }
};