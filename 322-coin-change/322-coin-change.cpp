class Solution {
public:
    
    int find(int i,int sum,vector<int> &coins ,int amount,vector<vector<int>> &dp){
        
        if(amount == sum)return 0;
        else if(amount < sum || i == coins.size())return INT_MAX;
        
        if(dp[i][sum] != -1)return dp[i][sum];
        
         int x = INT_MAX;
        
        if(coins[i] <= amount)x = find(i,sum + coins[i],coins,amount,dp);
        
        int y = find(i+1,sum,coins,amount,dp);
        
        if(x == INT_MAX)return dp[i][sum] = y;
        
        else return dp[i][sum] = min(1+x,y);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount,-1));
        
        int ans = find(0,0,coins,amount,dp);
        
        if(ans == INT_MAX)return -1;
        
        return ans;
    }
};