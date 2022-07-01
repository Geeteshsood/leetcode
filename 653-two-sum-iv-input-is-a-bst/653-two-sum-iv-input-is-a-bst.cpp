class Solution {
public:
    
    unordered_set<int> s;    
    
    bool dfs(TreeNode* root,int k){
        
        if(root == NULL)return false;
        
        if(s.find(k - root->val) != s.end())return true;
        else s.insert(root->val);
        
        return dfs(root->left,k) || dfs(root->right,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        return dfs(root,k);
        
    }
};