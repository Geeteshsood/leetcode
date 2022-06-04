class Solution {
public:
    
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        
        int sum = accumulate(rods.begin(),rods.end(),0);
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,INT_MIN));
        
        sum = sum/2;
        
        dp[0][sum] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=-sum;j<=sum;j++){
                
                dp[i][sum + j] = max(dp[i][sum + j],dp[i-1][sum + j]);
                
                if(j + rods[i-1] <= sum && dp[i-1][sum + j+rods[i-1]] != INT_MIN){
                    dp[i][sum + j] = max(dp[i][sum + j],dp[i-1][sum + j+rods[i-1]]);
                }
                if(j - rods[i-1] >= -sum && dp[i-1][sum + j-rods[i-1]] != INT_MIN){
                    dp[i][sum + j] = max(dp[i][sum + j],dp[i-1][sum + j-rods[i-1]] + rods[i-1]);
                }
            }
        }
        
//         for(int i=0;i<=n;i++){
//             for(int j=-sum;j<=sum;j++){
//                 if(dp[i][j+sum] == INT_MIN)cout<<"*"<<" ";
//                 else cout<<dp[i][j+sum]<<" ";
//             }
//             cout<<endl;
//         }
        
        return dp[n][sum];
    }
};