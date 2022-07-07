class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        vis[i]=1;
        for(auto k:adj[i]){
            if(!vis[k]){
                dfs(k,adj,vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        
        int m=con.size();
        if(m < n-1)return -1;
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<m;i++){
            int u = con[i][0] , v = con[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        int c=0;
        for(int j=0;j<n;j++){
            if(!vis[j]){
                c++;
                dfs(j,adj,vis);
            }
        }
        
        return c-1;
    }
};