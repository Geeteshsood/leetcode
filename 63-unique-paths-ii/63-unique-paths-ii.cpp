class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        int m = mat.size() , n = mat[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n));
        
        dp[0][0] = !mat[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(mat[i][j] == 1)continue;
                
                if(i == 0 && j == 0)continue;
                
                if(i == 0)dp[i][j] = dp[i][j-1];
                else if(j == 0)dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
      return dp[m-1][n-1];
    }
};