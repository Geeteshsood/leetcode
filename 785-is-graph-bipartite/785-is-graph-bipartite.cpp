class Solution {
public:
    
    typedef pair<int,int> pi;
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> col(n);
        queue<pi> q;
        
        
  for(int k=0;k<n;k++){ 
      
      if(col[k] != 0)continue;
      
        col[k] = -1;
        q.push({k,1});
        
        
        while(q.size()){
            
            int size = q.size();
            
            for(int i=0;i<size;i++){
                
                int node = q.front().first;
                int cur = q.front().second;
                
                q.pop();
                
                for(auto &it : graph[node]){
                    
                    if(col[it] == 0){
                        col[it] = cur;
                        q.push({it,-1*cur});
                    }
                    else if(col[it] != cur){
                        return false;
                    }
                }
            }
        }
  }
        return true;
    }
};