class Solution {
public:
    
    int dp[2][1001];
    
    int minimumWhiteTiles(string floor, int n, int len) {
        
        memset(dp,0,sizeof(dp));
        
        int m = floor.size();

        for(int i=0;i<n+1;i++){
            for(int j=1;j<=m;j++){
                
                if(i == 0){
                    dp[i][j] = (floor[j-1]-'0') + dp[i][j-1];
                    continue;
                }
                
                if(j-len>=0){
                    dp[i%2][j] = min((floor[j-1]-'0') + dp[i%2][j-1],dp[(i+1)%2][j-len]);
                }
                else dp[i%2][j] = 0;
            }
        }

     return dp[n%2][m];

    }
};