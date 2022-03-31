class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        bool player1 = false;
        
        vector<int> score(n+1);
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += piles[i];
            score[i+1] = sum;
        }
        
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int g=1;g<n;g++){
            
            player1 = !player1;
            
            for(int i=0,j=g;i<n && j<n;i++,j++){
                 
                 if(player1){
                     dp[i][j] = max(piles[i] + dp[i+1][j] , piles[j] + dp[i][j-1]);
                 }
                 else{
                     
                     int score1 = piles[i] + score[j+1]-score[i+1] - dp[i+1][j];
                     int score2 = piles[j] + score[j]-score[i] - dp[i][j-1];
                     
                     dp[i][j] = score[j+1] - score[i] - max(score1,score2);
                 }
            }
        }
        
     return dp[0][n-1] >= sum-dp[0][n-1];
    }
};