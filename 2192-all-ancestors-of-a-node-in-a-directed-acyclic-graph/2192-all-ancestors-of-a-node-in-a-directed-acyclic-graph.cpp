class Solution {
public:
    
   vector<vector<int>> ans,adj;
    
   void dfs(int i,int x,vector<int> &vis){

       for(auto &node : adj[i]){
           if(!vis[node]){
             vis[node] = true;
             ans[x].push_back(node);
             dfs(node,x,vis);
           }
           
       }
   }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        ans = vector<vector<int>>(n,vector<int>());
        adj = vector<vector<int>>(n,vector<int>());
        
        for(auto &it : edges){
            int  u = it[0], v = it[1];
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            
            vector<int> vis(n,false);
            
            dfs(i,i,vis);
        }
        
        for(int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        
     return ans;  
    }
};