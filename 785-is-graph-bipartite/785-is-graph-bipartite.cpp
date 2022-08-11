class Solution {
public:
    
    bool dfs(int i,int cur,vector<int> &col,vector<vector<int>> &graph){
        
        col[i] = cur;
        
        for(auto &it : graph[i]){
            
            if(col[it] == 0){ // not colored yet
                if(!dfs(it,-1*cur,col,graph))return false;
            }
            else if(col[it] == cur){
                return false;
            }
        }
        
       return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> col(n);
        
        for(int i=0;i<n;i++){
          if(col[i] != 0)continue ;
          if(!dfs(i,1,col,graph))return false;
        }
        
        return true;
    }
};