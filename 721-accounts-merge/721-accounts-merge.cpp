class Solution {
public:
    
    int find(int x,vector<int> &par){
        
        if(x == par[x])return x;
        
        return par[x] = find(par[x],par);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        
        vector<int> par(n);
        
        for(int i=0;i<n;i++)par[i] = i;

        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            
          for(int j=1;j<accounts[i].size();j++){
             
              if(!mp.count(accounts[i][j])){
                  mp[accounts[i][j]] = i;
                  continue;
              }
              
              int k = mp[accounts[i][j]];
              
              if(k != i){
                  
                  int lx = find(i,par);
                  int ly = find(k,par);
                  
                  if(lx != ly)par[lx] = ly;
              }
             
          }
            
        }
        
        unordered_map<int,set<string>> dp;
        
        for(int i=0;i<n;i++){
            
            par[i] = find(i,par);
           
            for(int j=1;j<accounts[i].size();j++){
                
                dp[par[i]].insert(accounts[i][j]);
                
            }
        }
       
        vector<vector<string>> res(dp.size());
        int i = 0;
        
        for(auto &it : dp){
            res[i].push_back(accounts[it.first][0]);
            for(auto &x : it.second){
                res[i].push_back(x);
            }
            i++;
        }
        
     return res;   
    }
};