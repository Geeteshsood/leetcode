class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(4);
        dp[0] = true;
        
        for(int i=1;i<n;i++){
   
            if(nums[i] == nums[i-1]){
                dp[(i+1)%4] = dp[(i-1)%4];
                
                if(i > 1 && nums[i] == nums[i-2] && !dp[(i+1)%4]){
                    dp[(i+1)%4] = dp[(i-2)%4];
                }
            }
            else if(i > 1 && ((nums[i] == nums[i-1]+1 ) && (nums[i] == nums[i-2] + 2))){
                 dp[(i+1)%4] = dp[(i-2)%4];
            }
            else dp[(i+1)%4] = false;
            
        }
        
        return dp[n%4];
    }
};