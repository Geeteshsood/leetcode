class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int mini = -sum , maxi = sum;
        
        unordered_map<int,unordered_map<int,int>> dp;
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            
           for(int j=mini;j<=maxi;j++){
               
              dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j+nums[i-1]];
               
           }
        }
        
        return dp[n][target];
    }
};