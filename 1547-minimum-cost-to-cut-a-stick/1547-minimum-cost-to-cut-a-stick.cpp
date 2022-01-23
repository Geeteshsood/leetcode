class Solution {
public:
    
    int find(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        
        if(i > j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<=j;k++){
            
            int x = find(i,k-1,cuts,dp);
            int y = find(k+1,j,cuts,dp);
            
            ans = min(ans,cuts[j+1]-cuts[i-1]+ x + y);
        }
        
       return dp[i][j] = ans; 
    }
    
    int minCost(int len, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(len);
        sort(cuts.begin(),cuts.end());
        
        int n = cuts.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return find(1,n-2,cuts,dp);
    }
};