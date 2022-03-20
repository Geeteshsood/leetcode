class Solution {
public:
    
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        
        int target = 1<<n;
        vector<int> dp(target,INT_MIN);
        
        dp[0] = 0;
        
        for(int mask=0;mask<target;mask++){
            
           int setbits = __builtin_popcount(mask);
            
           if(setbits % 2 != 0)continue; // odd bits is not possible as we always have to choose 2 numbers
            
           if(dp[mask] == INT_MIN)continue;      // if this cannot be achieved
        
           int opt = setbits/2;                 // calculating how many operation have been performed
            
           for(int i=0;i<n;i++){
               
               if(mask & (1<<i))continue;
      
               for(int j=i+1;j<n;j++){
                   
                   if(mask & (1<<j))continue;               
                   
                   int nmask = mask | (1<<i) | (1<<j);   // setting bits of 2 chosen numbers (i,j)
                   
                   dp[nmask] = max(dp[nmask] , (opt+1)*gcd(nums[i],nums[j]) + dp[mask]);
               }
           }
            
        }
      
        return dp[target-1];
    }
};