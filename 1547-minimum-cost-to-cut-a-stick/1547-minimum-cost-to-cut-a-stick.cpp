class Solution {
public:
    int minCost(int len, vector<int>& cuts){
        
        cuts.push_back(0);
        cuts.push_back(len);
        sort(cuts.begin(),cuts.end());
        
        int n = cuts.size() , x = 0;
        
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int g=1;g<n-1;g++){
            for(int i=1,j=g;i<n-1 && j<n-1;i++,j++){
                
                int val = 0 , ans = INT_MAX;
                
                for(int k=i;k<=j;k++){
                    
                    val = cuts[j+1]-cuts[i-1];
                    
                    if(k-1>=1)val += dp[i][k-1];
                    if(k+1<n-1)val += dp[k+1][j];
                    
                    ans = min(ans,val);
                }
                
                dp[i][j] = ans;
            }
        }
        
    return dp[1][n-2];
    }
};