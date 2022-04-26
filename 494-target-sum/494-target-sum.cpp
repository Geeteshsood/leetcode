class Solution {
public:
    
    int dp[22][4002];
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int mini = -sum , maxi = sum;
        
        memset(dp,0,sizeof(dp));
        
        dp[0][2000] = 1;
        
        for(int i=1;i<=n;i++){
            
           for(int j=mini;j<=maxi;j++){
               
              dp[i][j+2000] = dp[i-1][j-nums[i-1]+2000] + dp[i-1][j+nums[i-1]+2000];
               
           }
        }
        
        return dp[n][target+2000];
    }
};