class Solution {
public:
    
     bool dfs(vector<int> adj[],int src,vector<bool> &vis,vector<bool> &path){
        
        vis[src] = true;
        path[src] = true;
        
        for(auto i:adj[src]){
         
            if(path[i])return false;
            
            if(!vis[i]){
                if(!dfs(adj,i,vis,path)){
                    return false;
                }
            }
         
        }
        
        path[src] = false;
        
     return true;   
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
           vector<int> adj[n];
        
           for(auto it : pre){
               int u = it[0] , v = it[1];
               
               adj[u].push_back(v);
           }
        
       vector<bool> vis(n,false);
       vector<bool> path(n,false);
       
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(adj,i,vis,path)){
                    return false;
                }
            }
        }
        
      return true; 
    }
};