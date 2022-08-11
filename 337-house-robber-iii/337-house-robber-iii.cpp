class Solution {
public:
    typedef pair<int,int> pi;
    
    pi dfs(TreeNode* root){
        
        if(root == NULL)return {0,0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        int rob = left.second + right.second + root->val;
        
        int notrob = max(left.first , left.second) + max(right.first , right.second);
        
        return {rob,notrob};
    }
    int rob(TreeNode* root) {
        
        auto it = dfs(root);
        
        return max(it.first , it.second);
    }
};