class Solution {
public:
    
    int find(int i,vector<int> &nums,vector<int> &dp){
        
         if(i >= nums.size())return 0;
        
         if(dp[i] != -1)return dp[i];
        
         int x = nums[i] + find(i+2,nums,dp);
         int y = find(i+1,nums,dp);
       
        return dp[i] = max(x,y);
    }
    
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        
        return find(0,nums,dp);
    }
};