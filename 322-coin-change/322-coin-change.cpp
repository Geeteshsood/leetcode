class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX));
        
        for(int i=0;i<n;i++)dp[i][0] = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                
                if(i == 0){
                    if(j-coins[i]>=0 && dp[i][j-coins[i]] != INT_MAX){
                        dp[i][j] = 1 + dp[i][j-coins[i]];
                    }
                }
                else{
                    if(j-coins[i]>=0 && dp[i][j-coins[i]] != INT_MAX){
                        dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j-coins[i]]);
                    }
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n-1][amount] == INT_MAX)return -1;
        
        return dp[n-1][amount]-1;
    }
};