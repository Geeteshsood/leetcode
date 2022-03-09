class Solution {
public:
    
    TreeNode* createBinaryTree(vector<vector<int>>& edges) {
        
        unordered_map<int,TreeNode*> mp;
        unordered_map<TreeNode*,TreeNode*> par;
        
        TreeNode* parent;
        TreeNode* child;
        TreeNode*x;
        
        for(auto &it : edges){
            
            int u = it[0] , v = it[1] , isLeft = it[2];
            
            if(mp.count(u)){
                parent = mp[u];
            }
            else{
                mp[u] = new TreeNode(u);
                parent = mp[u];
            }
            
            if(mp.count(v)){
                child = mp[v];
            }
            else child = mp[v] = new TreeNode(v);
            
            if(isLeft)parent->left = child;
            else parent->right = child;
                
            par[child] = parent;
            x = child;
        }
        
        while(par.count(x)){
            x = par[x];
        }
        
     return x;   
    }
};