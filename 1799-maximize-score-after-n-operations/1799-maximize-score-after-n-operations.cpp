class Solution {
public:
    
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        
        int target = 1<<n;
        vector<int> dp(target,INT_MIN);
        dp[0] = 0;
        
        for(int mask=0;mask<target;mask++){
            
           int setbits = __builtin_popcount(mask);
            
           if(setbits % 2 != 0)continue;
            
           if(dp[mask] == INT_MIN)continue;
        
           int opt = setbits/2;
            
           for(int i=0;i<n;i++){
               
               if(mask & (1<<i))continue;
      
               for(int j=i+1;j<n;j++){
                   
                   if(mask & (1<<j))continue;
                   
                   int nmask = (mask | (1<<i)) | (mask | (1<<j));
                   
                   dp[nmask] = max(dp[nmask] , (opt+1)*gcd(nums[i],nums[j]) + dp[mask]);
               }
           }
            
        }
      
        return dp[target-1];
    }
};