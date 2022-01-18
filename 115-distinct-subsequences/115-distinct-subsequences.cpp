class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n =  s.length() , m = t.length() , mod = 1e9 + 7;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int j=0;j<n+1;j++){
            dp[0][j] = 1;
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                }    
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    
        return dp[m][n];
    }
};