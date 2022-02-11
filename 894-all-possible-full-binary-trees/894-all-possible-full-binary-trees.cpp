class Solution {
public:
  
    vector<TreeNode*> generate(int n){
        
        if(n == 1){
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        
        vector<TreeNode*> ans;
        
        for(int i=1;i<=n-2;i+=2){
            
            auto v1 = generate(i);
            auto v2 = generate(n-1-i);
            
            for(auto &x : v1){
                for(auto &y : v2){
                   TreeNode* root = new TreeNode(0);
                   root->left = x;
                   root->right = y;
                   ans.push_back(root);
                }
            }
        }
       
        return ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
          return generate(n);
    }
};