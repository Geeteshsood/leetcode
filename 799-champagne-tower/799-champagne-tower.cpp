class Solution {
public:
    double champagneTower(int k, int r, int c) {
        
        if(r >= k || c > r)return 0;
        
        vector<vector<double>> dp(r+2,vector<double>(r+2));
        
        dp[0][0] = (double)k;
        
        for(int i=0;i<=r;i++){
            bool flag = true;
            for(int j=0;j<=i;j++){
                if(dp[i][j]<=1)continue;
                
                flag = false;
                double rem = dp[i][j]-(double)1;
                dp[i][j] = (double)1;
                dp[i+1][j]   += rem/2;
                dp[i+1][j+1] += rem/2;
            }
            
            if(flag)break;
        }
        //   for(int i=0;i<=r;i++){
        //     for(int j=0;j<=i;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[r][c];
    }
};