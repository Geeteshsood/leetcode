class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m = s1.length() , n = s2.length();
        
        if(m + n != s3.length())return false;
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        
        dp[0][0] = true;
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                
                int k = i+j;
                
                if(i>0 && j>0 && s1[i-1] == s3[k-1] && s2[j-1] == s3[k-1]){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(i>0 && s1[i-1] == s3[k-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(j>0 && s2[j-1] == s3[k-1]){
                    dp[i][j] = dp[i][j-1];
                }
                
            }
        }
        
      return dp[m][n];
    }
};