class Solution {
public:
    
    
   TreeNode* dfs(int root,vector<int> &left,vector<int> &right){
        
        // cout<<root<<endl;

        TreeNode* node = new TreeNode(root);
        
        if(left[root]!=-1)node->left = dfs(left[root],left,right);
        else node->left = NULL;
       
        if(right[root]!=-1)node->right = dfs(right[root],left,right);
        else node->right = NULL;
       
        return node;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& edges) {
        
         int high = INT_MIN;
         for(auto &it : edges){
             high = max({high,it[0],it[1]});
         }
        
         vector<int> vis(high+1,false);
         vector<int> left(high+1,-1);
         vector<int> right(high+1,-1);
        
         for(auto &i : edges){
             int u = i[0] , v = i[1] , wt = i[2];
             vis[v] = true;
             
             if(wt == 1)left[u]=v;
             if(wt == 0)right[u]=v;
             // cout<<"*"<<endl;
         }

        
         for(auto &i : edges){
             int u = i[0] , v = i[1] , wt = i[2];
             if(!vis[u]){
                 return dfs(u,left,right);
             }
             if(!vis[v]){
                 return dfs(v,left,right);
             }
         }
         return NULL;
        
    }
};