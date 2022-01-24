class Solution {
public:
    
    unordered_map<int,int> mp;
    
    int find(int i,vector<int> &nums,vector<int> &dp){
        
       if(i >= nums.size()){
           return 0;
       }
        
       if(dp[i] != -1)return dp[i];
        
       int idx = 1;
        
       if(mp.count(nums[i]+1)){
           idx += 1;
       }
        
       int x = mp[nums[i]]*nums[i] +  find(i+idx,nums,dp);
        
       int y = find(i+1,nums,dp);
        
      return dp[i] = max(x,y);
    }
    
    int deleteAndEarn(vector<int>& v) {
        
        for(auto &it : v){
            mp[it]++;
        }
        
        vector<int> nums;
        
        for(auto [x,y] : mp){
            nums.push_back(x);
        }
        
        int n = nums.size();
        vector<int> dp(n,-1);
        
        sort(nums.begin(),nums.end());
        
        return find(0,nums,dp);
    }
};