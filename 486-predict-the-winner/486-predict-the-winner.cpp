typedef pair<int,int> pi;
class Solution {
public:
    
    pi find(int i,int j,vector<int> &nums,bool flag,vector<vector<pi>> &dp){
        
        if(dp[i][j].first != -1){
            return dp[i][j];
        }
        
        if(i == j){
            if(flag)return dp[i][j] = {nums[i],0};
            else return dp[i][j] = {0,nums[j]};
        }
        
        if(flag){ 
            auto[fp1,sp1] = find(i+1,j,nums,false,dp);
            auto[fp2,sp2] = find(i,j-1,nums,false,dp);
            
            fp1 += nums[i] , fp2 += nums[j];
            
            if(fp1 > fp2)return dp[i][j] = {fp1,sp1};
            else return dp[i][j] = {fp2,sp2};
        }
        else{
            
            auto[fp1,sp1] = find(i+1,j,nums,true,dp);
            auto[fp2,sp2] = find(i,j-1,nums,true,dp);
            
            sp1 += nums[i] , sp2 += nums[j];
            
            if(sp1 > sp2)return dp[i][j] = {fp1,sp1};
            else return dp[i][j] = {fp2,sp2};
        }
     
     return dp[i][j] = {-1,-1};
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<pi>> dp(n,vector<pi>(n,{-1,-1}));
        auto [fp,sp] = find(0,n-1,nums,true,dp);
        
      return fp>=sp;  
    }
};