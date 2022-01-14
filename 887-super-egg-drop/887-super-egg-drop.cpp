class Solution {
public:
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(k+1,vector<int>(n+1));
        
        for(int f=1;f<n+1;f++)dp[1][f] = f;
            
        for(int e=2;e<k+1;e++){
            for(int f=1;f<n+1;f++){
                int ans = INT_MAX ,val = 0;
                
                int start = 1 , end = f;
                
                while(start <= end){
                     int mid = end - (end-start)/2;
                     int up = dp[e][f-mid] , down = dp[e-1][mid-1];
                    
                     if(up > down){
                         start = mid + 1;
                     }
                     else end = mid - 1;
                    
                     val = 1 + max(down , up);
                     ans = min(val,ans);
                }
                dp[e][f] = ans;
            }
        }
        
     return dp[k][n];
    }
};