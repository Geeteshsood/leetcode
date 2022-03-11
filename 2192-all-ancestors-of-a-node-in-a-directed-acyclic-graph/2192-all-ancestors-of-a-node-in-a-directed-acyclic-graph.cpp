class Solution {
public:
    
    void dfs(int i,int an,vector<vector<int>> &res,vector<vector<int>> &adj){
        
        for(auto &x : adj[i]){
            
            if(res[x].empty() || res[x].back() != an){
                res[x].push_back(an);
                dfs(x,an,res,adj);
            }
        }
        
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
        
        vector<vector<int>> res(n,vector<int>()),adj(n,vector<int>());
        
        for(auto &it : edges){
             int u = it[0] , v = it[1];
             adj[u].push_back(v);
        }
        
        for(int i=0;i<n;i++){
            dfs(i,i,res,adj);
        }
        
        return res;
    }
};