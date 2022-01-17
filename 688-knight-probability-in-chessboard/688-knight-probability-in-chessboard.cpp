class Solution {
public:
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<pair<int,int>> dir {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
        vector<vector<double>> dp(n,vector<double>(n,0));
        
        double lev = 0, prob = 1;
        
        queue<pair<int,int>> q;
        q.push({row,column});
        dp[row][column] = 1;
        
        while(q.size() && lev<k){
            
           int size = q.size();
           prob = 0;
            
           for(int idx = 0;idx<size;idx++){
              
              int i = q.front().first;
              int j = q.front().second;
               
              q.pop();
               
              for(auto it:dir){
                  
                 int x = i + it.first;
                 int y = j + it.second;
                  
                  if(x>=0 && y>=0 && x<n && y<n){
                      
                      if(dp[x][y] == 0){
                          q.push({x,y});
                      }
                      
                      dp[x][y] += dp[i][j]/8;
                      
                      if(lev == k-1){
                          prob+=(dp[i][j]/8);
                      } 
                  }
              }
               
             dp[i][j] = 0;
           }
            
           lev++; 
        }

     return prob;
    }
};