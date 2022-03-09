class Solution {
public:
    
   unordered_map<int,int> vis,left,right;
    
   TreeNode* dfs(int root){
        
        TreeNode* node = new TreeNode(root);
        
        if(left.count(root))node->left = dfs(left[root]);
        else node->left = NULL;
       
        if(right.count(root))node->right = dfs(right[root]);
        else node->right = NULL;
       
        return node;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& edges) {
        
         for(auto &i : edges){
             int u = i[0] , v = i[1] , wt = i[2];
             vis[v] = true;
             
             if(wt == 1)left[u]=v;
             if(wt == 0)right[u]=v;
         }
        
         for(auto &i : edges){
             
             int u = i[0] , v = i[1];
             
             if(!vis.count(u))return dfs(u);
             if(!vis.count(v))return dfs(v);
             
         }
        
         return NULL;
    }
};