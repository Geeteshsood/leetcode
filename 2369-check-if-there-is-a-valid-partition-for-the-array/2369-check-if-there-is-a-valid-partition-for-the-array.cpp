class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n+1);
        dp[0] = true;
        
        for(int i=1;i<n;i++){
   
            if(nums[i] == nums[i-1]){
                dp[i+1] = dp[i+1] | dp[i-1];
                
                if(i > 1 && nums[i] == nums[i-2]){
                    dp[i+1] = dp[i+1] | dp[i-2];
                }
            }
            else if(i > 1 && ((nums[i] == nums[i-1]+1 ) && (nums[i] == nums[i-2] + 2))){
                 dp[i+1] = dp[i+1] | dp[i-2];
            }
            
            
        }
        
        return dp[n];
    }
};