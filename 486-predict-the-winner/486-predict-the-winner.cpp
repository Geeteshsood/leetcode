class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n)) ,sum(n,vector<int>(n));
        
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(j>0)sum[i][j] = nums[j] + sum[i][j-1];
               else sum[0][0] = nums[0];
            }
        }
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                if(g == 0){
                    dp[i][j] = nums[i];
                    continue;
                }
                
                int x = nums[j] + sum[i][j-1] - dp[i][j-1];
                int y = nums[i] + sum[i+1][j] - dp[i+1][j];
                
                dp[i][j] = max(x,y);
            }
        }

        int total = sum[0][n-1],fp = dp[0][n-1];
        int sp = total-fp;
        
     return fp>=sp;
    }
};