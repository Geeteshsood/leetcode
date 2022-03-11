// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
        
//        long int mod=1000000007;   
//        vector<int> dp(target+1,0);
        
//         dp[0]=1;
        
//        for(int j=0;j<=target;j++){  
//           for(int i=0;i<nums.size();i++){
//               if(j-nums[i]>=0)
//                 dp[j]+=dp[j-nums[i]]%mod;
//             }
//         }
        
// return dp[target];   
        
//     }
// };

class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int t) {
        
        long int m = 1e9 + 7;
        
        int n = nums.size();
        vector<int> dp(t+1,0);
        dp[0] =1;
        
        for(int i = 1 ;i<=t ; i++){
            
            for(int j = 0 ; j<n ; j++){
                
                if(nums[j] <= i){
                    dp[i] += dp[i - nums[j]]%m;
                }
                
            }
            
        }
        
        return dp[t];
        
    }
};