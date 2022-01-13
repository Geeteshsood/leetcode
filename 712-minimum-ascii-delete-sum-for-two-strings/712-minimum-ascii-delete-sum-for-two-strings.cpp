class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        
        int m = s.length() , n = t.length();
    
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        
        for(int i=1;i<m+1;i++){
            dp[i][0] = (int)s[i-1] + dp[i-1][0];
        }
        for(int j=1;j<n+1;j++){
            dp[0][j] = (int)t[j-1] + dp[0][j-1];
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min((int)s[i-1] + dp[i-1][j] , (int)t[j-1] + dp[i][j-1]);
                }
            }
        }
        
      return dp[m][n];
    }
};