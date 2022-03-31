class Solution {
public:
    
    int find(int i,int j,vector<int> &piles,vector<vector<int>> &dp){
        
         if(i == j){
             return piles[i];
         }
         else if(i > j)return 0;
        
         if(dp[i][j] != -1)return dp[i][j];
        
         int sc1 = piles[i] + min(find(i+2,j,piles,dp),find(i+1,j-1,piles,dp));
         int sc2 = piles[j] + min(find(i,j-2,piles,dp),find(i+1,j-1,piles,dp));
        
        return dp[i][j] = max(sc1,sc2);
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size() , total = 0;
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        for(int i=0;i<n;i++){
            total += piles[i];
        }
        
        int p1 = find(0,n-1,piles,dp);
        
        return p1>=total - p1;
    }
};