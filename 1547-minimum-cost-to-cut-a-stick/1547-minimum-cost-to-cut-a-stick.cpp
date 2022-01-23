class Solution {
public:
    int minCost(int len, vector<int>& cuts){
        
        sort(cuts.begin(),cuts.end());
        int n = cuts.size() , x = 0;
        
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                
                int val = 0 , ans = INT_MAX;
                
                for(int k=i;k<=j;k++){
                    
                    if(j<n-1 && i>0)x = cuts[j+1]-cuts[i-1];
                    else if(i==0 && j==n-1)x = len;
                    else if(i==0)x = cuts[j+1];
                    else if(j==n-1)x = len-cuts[i-1];
                    
                    val = x;
                    if(k-1>=0)val += dp[i][k-1];
                    if(k+1<n)val += dp[k+1][j];
                    
                    ans = min(ans,val);
                }
                
                dp[i][j] = ans;
            }
        }
        
    return dp[0][n-1];
    }
};