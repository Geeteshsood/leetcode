class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size() , target = 0 , sum = 0;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        if(sum%k == 0){
            target = sum/k;
        }
        else return false;
        
        vector<int> dp(1<<n,-1);
        dp[0] = 0;
        
        for(int mask=0;mask<(1<<n);mask++){
            
            if(dp[mask] == -1)continue;
            
            for(int i=0;i<n;i++){
                
                if( !(mask & (1<<i))  && (dp[mask] + nums[i] <= target)){
                     dp[mask|(1<<i)] = (dp[mask] + nums[i])%target ;
                }
            }
        }
     
        return !dp[(1<<n)-1];
    }
};