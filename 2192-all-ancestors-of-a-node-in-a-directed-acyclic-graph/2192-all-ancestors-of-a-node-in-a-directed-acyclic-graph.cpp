class Solution{
public:
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
         vector<vector<int>> ans(n,vector<int>());
         vector<vector<int>> adj(n,vector<int>());
        
        for(auto &it : edges){
            int  u = it[0], v = it[1];
            adj[v].push_back(u);
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            
            vector<int> vis(n,false);
            q.push(i);
            
            while(q.size()){
                
                int x = q.front();
                q.pop();
                
                for(auto &y : adj[x]){
                    if(!vis[y]){
                        vis[y] = true;
                        ans[i].push_back(y);
                        q.push(y);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        
     return ans;  
    }
};