class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        if(stones[1]!=1)return false;
        
        if(n == 2)return true;
        
        dp[1][1] = true;
        
        for(int i=2;i<n;i++){
            
            for(int j=1;j<i;j++){
                
                int k = stones[i]-stones[j];
                
                bool flag = false;
                
                if(k-1>=0 && k-1<n)flag = flag || dp[j][k-1];
                if(k<n)flag = flag || dp[j][k];
                if(k+1<n)flag = flag || dp[j][k+1];
                
                if(k<n)dp[i][k] = flag;
                
                if(i == n-1 && flag){
                    return true;
                }
            }
        }
        
     return false;
    }
};