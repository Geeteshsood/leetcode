class Solution {
public:
    
    void dfs(TreeNode* root,int &ans,int &cnt,int k){
        
        if(root == NULL || ans != -1)return ;
        
        dfs(root->left,ans,cnt,k);
        
        cnt++;
        if(cnt == k){
            ans = root->val;
            return ;
        }
        
        dfs(root->right,ans,cnt,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
       int ans = -1,cnt = 0;
        
       dfs(root,ans,cnt,k);
        
       return ans;
    }
};