class Solution {
public:
    
    int find(int i,int j,int ls,int le,vector<int> &cuts,vector<vector<int>> &dp){
        
        if(i > j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<=j;k++){
            
            int x = find(i,k-1,ls,cuts[k],cuts,dp);
            int y = find(k+1,j,cuts[k],le,cuts,dp);
            
            ans = min(ans,le-ls + x + y);
        }
        
       return dp[i][j] = ans; 
    }
    
    int minCost(int len, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        
        int n = cuts.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return find(0,n-1,0,len,cuts,dp);
    }
};