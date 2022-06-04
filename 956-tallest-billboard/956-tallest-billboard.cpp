class Solution {
public:
    
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        
        int sum = accumulate(rods.begin(),rods.end(),0);
        sum = sum/2;
        
        vector<vector<int>> dp(n+1,vector<int> (5001,INT_MIN));
        
        dp[0][2500] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=-sum;j<=sum;j++){
                
                dp[i][2500 + j] = max(dp[i][2500 + j],dp[i-1][2500 + j]);
                
                if(j + rods[i-1] <= sum && dp[i-1][2500 + j+rods[i-1]] != INT_MIN){
                    dp[i][2500 + j] = max(dp[i][2500 + j],dp[i-1][2500 + j+rods[i-1]]);
                }
                if(j - rods[i-1] >= -sum && dp[i-1][2500 + j-rods[i-1]] != INT_MIN){
                    dp[i][2500 + j] = max(dp[i][2500 + j],dp[i-1][2500 + j-rods[i-1]] + rods[i-1]);
                }
            }
        }
        
//         for(int i=0;i<=n;i++){
//             for(int j=-sum;j<=sum;j++){
//                 if(dp[i][j+2500] == INT_MIN)cout<<"*"<<" ";
//                 else cout<<dp[i][j+2500]<<" ";
//             }
//             cout<<endl;
//         }
        
        return dp[n][2500];
    }
};