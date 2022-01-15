class Solution{
public:
    
    int find(int i,int j,vector<int> &nums,bool flag,vector<vector<int>> &dp){
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == j){
            if(flag)return nums[i];
            else return -nums[i];
        }
        
        int val = 0;
        
        if(flag){ 
            int s1 = find(i+1,j,nums,false,dp);
            int s2 = find(i,j-1,nums,false,dp);
            
            s1 += nums[i] , s2 += nums[j];
            
            val = max(s1,s2);
        }
        else{
            
            int s1 = find(i+1,j,nums,true,dp);
            int s2 = find(i,j-1,nums,true,dp);
            
            s1 -= nums[i] , s2 -= nums[j];
            
            val = min(s1,s2);
        }
     
     return dp[i][j] = val ;
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int score = find(0,n-1,nums,true,dp);
        
      return score>=0;  
    }
};