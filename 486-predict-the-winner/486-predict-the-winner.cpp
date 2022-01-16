class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(j>0)dp[i][j] = nums[j] + dp[i][j-1];
               else dp[0][0] = nums[0];
            }
        }
        
        for(int g=1;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                dp[i][j] -= min(dp[i][j-1],dp[i+1][j]);
            }
        }

        int total = 0;
        for(int i=0;i<n;i++)total+=nums[i];
        
        int fp = dp[0][n-1];
        int sp = total-fp;
        
     return fp>=sp;
    }
};