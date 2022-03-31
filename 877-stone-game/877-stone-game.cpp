class Solution {
public:
    typedef pair<int,int> pi;
    
    pi find(int i,int j,vector<int> &piles,bool flag,vector<vector<pi>> &dp){
        
         if(i==j){
             return {piles[i],0};
         }
        
         if(dp[i][j].first != -1 && dp[i][j].second != -1)return dp[i][j];
        
         auto s1 = find(i+1,j,piles,!flag,dp);
         auto s2 = find(i,j-1,piles,!flag,dp);
        
         if(piles[i] + s1.first >= piles[j] + s2.first) return dp[i][j] = {piles[i] + s1.first,s1.second};
         else return dp[i][j] = {piles[j] + s2.first,s2.second};
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<pi>> dp(n,vector<pi>(n,{-1,-1}));
        
        pair<int,int> p = find(0,n-1,piles,true,dp);
        
        return p.first >= p.second;
    }
};