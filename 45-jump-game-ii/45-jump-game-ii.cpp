class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        
        dp[0] = nums[0];
        
        for(int i=1;i<n;i++){
            
            int val = i + nums[i];
            
            auto jmp = lower_bound(dp.begin(),dp.end(),i)-dp.begin();// tell us we can reach that point
                                                                     // with min jumps
            if(i == n-1)return jmp + 1;
            
            if(dp[jmp + 1] == INT_MAX && val > dp[jmp]){
                dp[jmp + 1] = val;
            }
            else if(dp[jmp + 1] != INT_MAX && val > dp[jmp+1]){
                dp[jmp + 1] = val;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        return 0;
    }
};