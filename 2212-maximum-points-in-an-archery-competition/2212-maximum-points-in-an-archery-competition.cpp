class Solution {
public:
    vector<int> maximumBobPoints(int n, vector<int>& al) {
       
        int m = al.size();
        int target = 1<<m , maxi = INT_MIN , amask = 0;
        
        vector<int> dp(target,INT_MIN);
        dp[0] = 0;
        
        for(int mask=0;mask<target;mask++){
            
            if(dp[mask] == INT_MIN)continue;
            
            int cur = 0;
            
            for(int i=0;i<12;i++){
                if(mask & (1<<i)){
                    cur += (al[i]+1);
                }
            }
            
            for(int i=0;i<12;i++){
                
                if(mask & (1<<i))continue;
                
                if(cur + al[i] + 1 <= n){
                    
                    int nmask = mask | (1<<i);
                    
                    dp[nmask] = dp[mask] + i;
                    
                    if(dp[nmask] > maxi){
                        maxi = dp[nmask];
                        amask = nmask;
                    }
                }
                
            }
            
        }
        
        vector<int> ans(m);
        int sum = 0;
        
        for(int i=0;i<12;i++){
            if(amask & (1<<i)){
                ans[i] = al[i]+1;
                sum += ans[i];
            }
        }
        
        ans[0] = n - sum;
        
        return ans;
    }
};