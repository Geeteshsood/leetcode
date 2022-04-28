class Solution {
public:
    
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        int n = nums.size() , val = 0;
        
        vector<int> dp(n+1);
        
        for(int i=0;i<n;i++){
            val += nums[i];
            dp[i+1] = val;
        }
        
        int sum = 0 , idx = -1;
        
        for(int i=0;i<n;i++){
            
            if(mp.count(nums[i])){
                idx = max(idx,mp[nums[i]]);
            }
            
            mp[nums[i]] = i;
            sum = max(sum,dp[i+1]-dp[idx+1]);
        }
        
       return sum;
        
    }
};