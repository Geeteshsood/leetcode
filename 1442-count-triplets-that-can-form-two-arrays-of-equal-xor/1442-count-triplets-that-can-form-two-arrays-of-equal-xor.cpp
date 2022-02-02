class Solution {
public:
    int countTriplets(vector<int>& arr) {
    
    int n = arr.size(),cnt = 0;
        
    vector<vector<int>> dp(n,vector<int>(n));
    
    for(int g=0;g<n;g++){
        for(int i=0,j=g;i<n && j<n;i++,j++){
            
            if(g == 0){
                dp[i][j] = arr[i];
                continue;
            }
            
            for(int k=i;k<j;k++){
                if(dp[i][k] == dp[k+1][j]){
                     cnt++;
                }
            }
            dp[i][j] = dp[i][i]^dp[i+1][j];
        }
    }
    
   return cnt; 
        
    }
    
};