class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int,int> dp;
        dp[-1] = true;
        
        for(int i=1;i<n;i++){
            
            
            if(nums[i] == nums[i-1]){
                dp[i] = dp[i] | dp[i-2];
                
                if(i > 1 && nums[i] == nums[i-2]){
                    dp[i] = dp[i] | dp[i-3];
                }
            }
            else if(i > 1 && ((nums[i] == nums[i-1]+1 ) && (nums[i] == nums[i-2] + 2))){
                 dp[i] = dp[i] | dp[i-3];
            }
            
            
        }
        
        return dp[n-1];
    }
};