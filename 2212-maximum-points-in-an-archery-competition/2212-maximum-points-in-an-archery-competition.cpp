class Solution {
public:
    
    int dp[100001][12];
    
    vector<int> maximumBobPoints(int n, vector<int>& al) {
        
        memset(dp,0,sizeof(dp));
        int m = al.size();
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<m;j++){
                if(j == 0){
                    continue;
                }
                else if(i-(al[j]+1) >= 0)dp[i][j] = max(dp[i][j-1] , j + dp[i-(al[j]+1)][j-1]);
                else dp[i][j] = dp[i][j-1];
            }
        }
 
        int i = n , j = m-1;
        vector<int> ans(m);
        int sum = 0;
        
        while(i>0 && j>0){
            if(j > 0 && dp[i][j] != dp[i][j-1]){
              ans[j] = al[j]+1;
              i = i - (al[j]+1);
            }
            sum += ans[j];
            j--;
        }
        
        ans[0] = n-sum;
        
        return ans;
    }
};