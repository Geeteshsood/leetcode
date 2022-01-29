class Solution {
public:
    
    int waysToSplit(vector<int>& nums) {
        
        int mod = 1e9 + 7;
        int n = nums.size() , total = 0;
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            total += nums[i];
            dp[i] = total;
        }

        int cnt = 0 ,left = 0  , sum = 0;
        
        for(int i=0;i<n-2;i++){
            
            left += nums[i];
            int val = 2*left;
            
            int j = lower_bound(dp.begin() + i + 1,dp.end(),val) - dp.begin();
            
            if(j > n-2)break;
            
            sum = total - left;
            sum = sum/2;
            
            val = left + sum;
            
            int k = upper_bound(dp.begin() + i + 1,dp.begin() + n-2,val) - dp.begin();
            
            while(k > i && true){
               int mid = dp[k]-dp[i];
               int right = total - left - mid;
               if(mid <= right)break;
               k--;
            }
            
            // cout<<i<<" "<<j<<" "<<k<<endl;
            if(k>=j)cnt = (cnt + k-j + 1)%mod;
        }
        
       return cnt; 
    }
};