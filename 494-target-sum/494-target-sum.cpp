class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int nsum = (sum + target)/2;
        
        if((sum+target)%2 != 0 || nsum < 0)return 0;
        
        int dp[n+1][nsum+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            
           for(int j=0;j<=nsum;j++){
               
               if(j-nums[i-1] >= 0){
                   dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
               }
               else dp[i][j] = dp[i-1][j];
           }
        }

        return dp[n][nsum];
    }
};