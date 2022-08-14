class Solution {
public:
    
    int find(int x,vector<int> &par){
        
        if(x == par[x])return x;
        
        return par[x] = find(par[x],par);
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        
        unordered_set<int> s;
        
        for(auto &it : res){
            s.insert(it);
        }
        
        vector<int> par(n);
        
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        
        for(auto &it : edges){
            
            int u = it[0] , v = it[1];
            
            if(s.find(u) != s.end() || s.find(v) != s.end() )continue;
            
            int lx = find(u,par);
            int ly = find(v,par);
            
            if(lx != ly){
                int x = max(lx,ly) , y = min(lx,ly);
                par[x]= y;
            }
    
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            par[i] = find(i,par); 
            if(par[i] == 0)cnt++;
        }
        
     return cnt;
    }
};