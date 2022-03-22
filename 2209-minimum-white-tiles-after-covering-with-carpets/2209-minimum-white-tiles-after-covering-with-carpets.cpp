class Solution {
public:
    
    int minimumWhiteTiles(string floor, int n, int len) {
        
        int m = floor.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<n+1;i++){
            for(int j=1;j<=m;j++){
                if(i == 0){
                    dp[i][j] = (floor[j-1]-'0') + dp[i][j-1];
                    continue;
                }
                
                if(j-len>=0){
                    dp[i][j] = min((floor[j-1]-'0') + dp[i][j-1],dp[i-1][j-len]);
                }

            }
        }

     return dp[n][m];

    }
};