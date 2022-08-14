class Solution {
public:
    
    int ans = INT_MIN;
    
void dfs(int i,vector<bool> &vis,vector<bool> &path,vector<int> &order,vector<vector<int>> &adj){
        
        vis[i] = true;
        path[i] = true;
            
        for(auto &it : adj[i]){
            
           if(!vis[it]){
               
               int x = order[it];
               order[it] = order[i] + 1;
               
               dfs(it,vis,path,order,adj);
               
               order[it] = x;
           } 
           else if(path[it]){
               int len = order[i] - order[it] + 1;
               ans = max(ans,len);
               return ;
           }
            
        }
        
         path[i] = false;
        
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++){
            if(edges[i] != -1)
            adj[i].push_back(edges[i]);
        }
        
        vector<bool> vis(n),path(n);
        vector<int> order(n,1);
        
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,vis,path,order,adj);
        }
        
        if(ans == INT_MIN)return -1;
        
        return ans;
        
    }
};