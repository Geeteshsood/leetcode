class Solution {
public:
    
    int find(int i,int j,vector<int> &piles,vector<vector<int>> &dp,bool player1,vector<int> &score){
        
         if(i==j){
             return 0;
         }
        
         if(dp[i][j] != -1)return dp[i][j];
        
         int s1 = find(i+1,j,piles,dp,!player1,score);
         int s2 = find(i,j-1,piles,dp,!player1,score);
        
         int total = score[j+1]-score[i] , val = 0;
        
         if(player1){
              val = max(s1 + piles[i] , s2 + piles[j]);
         }
         else{
              int p1 = total - (piles[i] + score[j+1]-score[i+1] - s1);
              int p2 = total - (piles[j] + score[j] - score[i] - s2);
              val = min(p1,p2);
         }
        
        return dp[i][j] = val;
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        vector<int> score(n+1);
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += piles[i];
            score[i+1] = sum;
        }
        
        int p1 =  find(0,n-1,piles,dp,true,score);
        
        return p1>=sum-p1;
    }
};