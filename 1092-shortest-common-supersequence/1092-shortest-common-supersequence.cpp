class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.size() , n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string ans;
        
        int i = m , j = n;
        
        while(i > 0 && j > 0){
            
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--,j--;
            }
            else{
                if(dp[i-1][j] >= dp[i][j-1]){
                    ans += str1[i-1];
                    i--;
                }
                else{
                    ans += str2[j-1];
                    j--;
                }
            }
            
        }
        reverse(ans.begin(),ans.end());
        
        if(i > 0)ans = str1.substr(0,i) + ans;
        if(j > 0)ans = str2.substr(0,j) + ans;
        
        
        return ans;
    }
};