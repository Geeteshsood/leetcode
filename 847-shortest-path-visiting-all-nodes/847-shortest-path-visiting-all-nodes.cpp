class Solution {
public:
    
    int find(int i,int mask,int &target,vector<vector<int>> &dp,vector<vector<int>> &memo){
        
        int n = dp.size();
        
        mask = mask|(1<<i);
 
        if(mask == target){
            mask = mask ^ (1<<i);
            return 0;
        }
        
        if(memo[i][mask] != -1)return memo[i][mask];
        
        int ans = INT_MAX;
        
        for(int j=0;j<n;j++){
            
            if(!(mask & (1<<j))){
                
                int val = dp[i][j] + find(j,mask,target,dp,memo);
                ans = min(ans,val);
                
            }
        }
            
        // mask = mask ^ (1<<i);

        return memo[i][mask] = ans;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        
         int n = graph.size() , ans = INT_MAX;
         
         vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
          for(int i=0;i<n;i++){
              for(auto &j : graph[i]){
                  dp[i][j] = 1;
              }
          }
        
          for(int k=0;k<n;k++){
              for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                      if(i == j){
                          dp[i][j] = 0;
                      }   
                      else if(dp[i][k] !=INT_MAX && dp[k][j] !=INT_MAX){
                          dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
                      }   
                  }
              }
          }
        
         int target = (1<<n)-1;
         int mask = 0;
        
         vector<vector<int>> memo(n,vector<int>(target + 1,-1));
        
         for(int i=0;i<n;i++){
             
             int val = find(i,mask,target,dp,memo);
             // cout<<mask<<endl;
             ans = min(ans,val);
         }
      
         return ans;
    }
};