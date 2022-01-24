class Solution {
public:
    
    int deleteAndEarn(vector<int>& v) {
        
        unordered_map<int,int> mp;
        
        for(auto &it : v){
            mp[it]++;
        }
        
        vector<int> nums;
        
        for(auto [x,y] : mp){
            nums.push_back(x);
        }
        
        int n = nums.size();
        vector<int> dp(n);
        
        sort(nums.begin(),nums.end());
        
        dp[0] = nums[0]*mp[nums[0]];
        
        for(int i=1;i<n;i++){
            
            int idx = 1;
            if(mp.count(nums[i]-1))idx = 2;
            
            if(i-idx>=0)dp[i] = max(dp[i-1],dp[i-idx] + nums[i]*mp[nums[i]]);
            else dp[i] = max(dp[i-1], nums[i]*mp[nums[i]]);
            
        }
       
        return dp[n-1];
    }
};