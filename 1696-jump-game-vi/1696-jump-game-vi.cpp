class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        
        dq.push_back(n-1);
        dp[n-1] = nums[n-1];
        
        int val = 0;
        
        for(int i=n-2;i>=0;i--){

            if(dq.back() > i + k)dq.pop_back();

            dp[i] = nums[i] + dp[dq.back()];
            
            while(dq.size() && dp[i] > dp[dq.front()]){
                dq.pop_front();
            }
            
            dq.push_front(i);
        }

        return dp[0];
    }
};