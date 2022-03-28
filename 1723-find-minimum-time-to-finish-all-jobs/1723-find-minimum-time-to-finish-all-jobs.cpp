class Solution {
public:

    int dp[12][1<<12];
    
    int minimumTimeRequired(vector<int>& jobs, int k){
        
        int n = jobs.size();
        
        int target = 1<<n;
        memset(dp,-1,sizeof(dp));
        
        
        for(int mask=0;mask<target;mask++){
            
            int sum = 0;
            
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    sum += jobs[i];
                }
            }
            
            dp[0][mask] = sum;
        }
        
        for(int i=1;i<k;i++){
            for(int mask=0;mask<target;mask++){
                int val = INT_MAX;
                for(int submask=mask;submask;submask=(submask-1)&mask){
                    val=min(val,max(dp[0][submask],dp[i-1][mask^submask]));
                    dp[i][mask] = val;
                }
            }
        }
        
        return dp[k-1][target-1];
    }
};