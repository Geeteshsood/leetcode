class Solution {
public:
    
    int minimumDifference(vector<int>& nums) {
        
        int n = nums.size() , total = 0;
        
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        int k = n/2;
        
        vector<int> dp[k+1];
        
        for(int mask=0;mask<(1<<k);mask++){
     
           int sum = 0 , cnt = 0;
            
           for(int i=0;i<k;i++) {
               if(mask & (1<<i)){
                   sum += nums[i+k];
                   cnt++;
               }
               
           }
           dp[cnt].push_back(sum);
        }
        
        for(int i=0;i<=k;i++){
            sort(dp[i].begin(),dp[i].end());
        }
        
        int ans = INT_MAX;
        
        for(int mask=0;mask<(1<<k);mask++){
            
           int sum = 0 , cnt = 0;
            
           for(int i=0;i<k;i++) {
               if(mask & (1<<i)){
                   sum += nums[i];
                   cnt++;
               }
           }
           
           int x = (total - 2*sum)/2;
            
           auto it = lower_bound(dp[k-cnt].begin(),dp[k-cnt].end(),x)-dp[k-cnt].begin();
            
           if(it != dp[k-cnt].size()){
               x = dp[k-cnt][it];
               ans = min(ans , abs(total - 2*(sum+x)));
           }
            
           if(it != 0){
               it--;
               x = dp[k-cnt][it];
               ans = min(ans , abs(total - 2*(sum+x)));
           }
        }
        
        return ans;
    }
};