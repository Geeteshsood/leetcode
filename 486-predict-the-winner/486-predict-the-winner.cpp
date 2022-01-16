class Solution {
public:
    
    int find(int i,int j,vector<int> &nums,vector<vector<int>> &dp){

        if(i == j)return nums[i];
        else if(i > j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int x = nums[i] + min(find(i+2,j,nums,dp),find(i+1,j-1,nums,dp));
        int y = nums[j] + min(find(i+1,j-1,nums,dp),find(i,j-2,nums,dp));
        
        return dp[i][j] = max(x,y);
    }
    
    bool PredictTheWinner(vector<int>& nums){
        
       int n = nums.size() , total = 0;
       for(int i=0;i<n;i++)total += nums[i];
        
       vector<vector<int>> dp(n,vector<int>(n,-1));
        
       int fp = find(0,n-1,nums,dp);
       int sp = total - fp;
        
     return fp>=sp;
    }
};