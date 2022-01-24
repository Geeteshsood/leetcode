class Solution {
public:
    
    unordered_map<int,int> mp;
    
    int find(int i,vector<int> &nums,vector<int> &dp){
        
       if(i >= nums.size()){
           return 0;
       }
        
       if(dp[i] != -1)return dp[i];
        
       int idx = mp[nums[i]];
        
       if(mp.count(nums[i]+1)){
           idx += mp[nums[i]+1];
       }
        
       int x = mp[nums[i]]*nums[i] +  find(i+idx,nums,dp);
        
       int y = find(i+mp[nums[i]],nums,dp);
        
      return dp[i] = max(x,y);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,-1);
        
        for(auto &it : nums){
            mp[it]++;
        }
        
        sort(nums.begin(),nums.end());
        
        return find(0,nums,dp);
    }
};