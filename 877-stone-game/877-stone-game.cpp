class Solution {
public:
    
    vector<int> find(int i,int j,vector<int> &piles,bool flag,vector<vector<vector<int>>> &dp){
        
         if(i==j){
             return {piles[i],0};
         }
        
         if(dp[i][j][0] != -1)return dp[i][j];
        
         auto s1 = find(i+1,j,piles,!flag,dp);
         auto s2 = find(i,j-1,piles,!flag,dp);
        
         if(piles[i] + s1[0] >= piles[j] + s2[0]) return dp[i][j] = {piles[i] + s1[0],s1[1]};
         else return dp[i][j] = {piles[j] + s2[0],s2[1]};
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        vector<int> score = find(0,n-1,piles,true,dp);
        
        return score[0] >= score[1];
    }
};