class Solution {
public:
    
    int ans = INT_MIN;
    
void dfs(int i,vector<bool> &vis,vector<bool> &path,vector<int> &order,vector<int> &edges){
        
        vis[i] = true;
        path[i] = true;
            
        int it = edges[i];
    
        if(it == -1){
            path[i] = false;
            return ;
        }
    
        if(!vis[it]){
            
            int x = order[it];
            order[it] = order[i] + 1;
            
            dfs(it,vis,path,order,edges);
            
            order[it] = x;
        } 
        else if(path[it]){
            int len = order[i] - order[it] + 1;
            ans = max(ans,len);
            return ;
        }
            
         path[i] = false;
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();

        vector<bool> vis(n),path(n);
        vector<int> order(n,1);
        
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,vis,path,order,edges);
        }
        
        if(ans == INT_MIN)return -1;
        
        return ans;
        
    }
};