class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int mini = -sum , maxi = sum;
        
        int dp[22][4*sum+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][2*sum] = 1;
        
        for(int i=1;i<=n;i++){
            
           for(int j=mini;j<=maxi;j++){
               
              dp[i][j+2*sum] = dp[i-1][j-nums[i-1]+2*sum] + dp[i-1][j+nums[i-1]+2*sum];
               
           }
        }
        
        return dp[n][target+2*sum];
    }
};