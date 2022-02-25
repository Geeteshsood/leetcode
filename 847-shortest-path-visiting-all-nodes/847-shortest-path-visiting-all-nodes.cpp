class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        int target = (1<<n)-1;
        vector<vector<bool>> vis(n,vector<bool> (target+1,false));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            int mask = (1<<i);
            if(mask == target)return 0;
            vis[i][mask] = true;
            q.push({i,mask});
        }
        
        int lev = 0;
        
        while(q.size()){
            
          int size = q.size();
            
          for(int i=0;i<size;i++){
              
              auto [node,mask] = q.front();
              q.pop();
              
              for(auto &itr : graph[node]){
                  
                  int nmask = mask | (1<<itr);
                  
                  if(nmask == target)return lev + 1;
                  
                  if(!vis[itr][nmask]){
                      
                      vis[itr][nmask] = true;
                      
                      q.push({itr,nmask});
                  }
              }
          }
          lev++;  
        }
        
     return lev;   
    }
};