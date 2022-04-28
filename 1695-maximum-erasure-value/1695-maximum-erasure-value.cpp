class Solution {
public:
    
    int maximumUniqueSubarray(vector<int>& nums) {
        
        vector<bool> vis(1e4+1,false);
        
        int n = nums.size() , val = 0;
        
        vector<int> dp(n+1);
        
        for(int i=0;i<n;i++){
            val += nums[i];
            dp[i+1] = val;
        }
        
        int sum = 0 , j = 0;
        
        for(int i=0;i<n;i++){
            
            if(vis[nums[i]]){
                
                while(j < i && nums[j] != nums[i]){
                    vis[nums[j]] = false;
                    j++;
                }
                j++;
                // cout<<i<<" "<<j<<endl;
                sum = max(sum,dp[i+1]-dp[j]);
            }
            else{
              vis[nums[i]] = true;
              sum = max(sum,dp[i+1]-dp[j]);
            }
        }
        
       return sum;
        
    }
};