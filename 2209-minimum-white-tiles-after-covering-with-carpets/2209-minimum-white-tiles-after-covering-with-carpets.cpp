class Solution {
public:
    
    int minimumWhiteTiles(string floor, int n, int len) {
        
        int m = floor.size();
        
        vector<vector<int>> dp(2,vector<int>(m+1));
        
        for(int j=1;j<=m;j++){
            dp[0][j] = (floor[j-1]-'0') + dp[0][j-1];
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=m;j++){

                if(j-len>=0){
                    dp[i%2][j] = min((floor[j-1]-'0') + dp[i%2][j-1],dp[(i+1)%2][j-len]);
                }
                else dp[i%2][j] = 0;
            }
        }

     return dp[n%2][m];

    }
};