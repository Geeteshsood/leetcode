class Solution {
public:
    int minimumWhiteTiles(string floor, int n, int len) {
        
        int m = floor.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<n+1;i++){
            
            for(int j=1;j<=m;j++){
                
                if(i == 0){
                    if(floor[j-1] == '1'){
                        if(j > 0)dp[i][j] = 1 + dp[i][j-1];
                        else dp[i][j] = 1;
                    }
                    else if(j > 0)dp[i][j] = dp[i][j-1];
                    
                    continue;
                }
                
                if(j-len>=0){
                    if(floor[j-1] == '1')dp[i][j] = min(1 + dp[i][j-1],dp[i-1][j-len]);
                    else dp[i][j] = min(dp[i][j-1],dp[i-1][j-len]);
                }

            }
        }
        
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
     return dp[n][m];

// "   1 0 1 1 0 1 0 1"        
//   0 1 1 2 3 3 4 4 5 
//   0 0 0 1 1 2 3 3 4 
//   0 0 0 0 0 1 1 2 3 

    }
};