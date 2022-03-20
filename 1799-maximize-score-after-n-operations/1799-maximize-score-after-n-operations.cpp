class Solution {
public:
    
    int dp[1<<14];
    
    int find(int mask,int opt,vector<int> &nums){
        
        int n = nums.size();
        
        if(dp[mask] != -1)return dp[mask];
        
        if(mask == ((1<<n)-1))return 0;
        
        for(int i=0;i<n;i++){
               
            if(mask & (1<<i))continue;

            for(int j=i+1;j<n;j++){
                
                if(mask & (1<<j))continue;               
                
                int nmask = mask | (1<<i) | (1<<j);   
                
                dp[mask] = max(dp[mask],opt*gcd(nums[i],nums[j]) + find(nmask,opt+1,nums));
            }
        }
            
      return dp[mask];
    }
    
    int maxScore(vector<int>& nums) {
    
         memset(dp,-1,sizeof(dp));
        
         return find(0,1,nums);
    }
};