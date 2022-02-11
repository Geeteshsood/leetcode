class Solution {
public:
  
    unordered_map<int,vector<TreeNode*>> dp;
    
    vector<TreeNode*> generate(int n){
        
        if(n == 1){
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        
        if(dp.count(n))return dp[n];
        
        vector<TreeNode*> ans;
        
        for(int i=1;i<=n-2;i+=2){
        
            for(auto &x : generate(i)){
                for(auto &y : generate(n-1-i)){
                   TreeNode* root = new TreeNode(0);
                   root->left = x;
                   root->right = y;
                   ans.push_back(root);
                }
            }
        }
       
        return dp[n] = ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
         
          return generate(n);
    }
};