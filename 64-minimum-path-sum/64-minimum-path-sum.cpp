class Solution {
public:
    
    bool isValid(int i,int j,int m,int n){
        
        return !(i<0 || j<0 || i>=m || j>=n);
            
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        vector<vector<int>> dir{{1,0},{0,1}};
        queue<pair<int,int>> q;
        
        q.push({0,0});
        dp[0][0] = grid[0][0];
        
        while(q.size()){
            
           auto[i,j] = q.front();
           q.pop();
            
           for(auto &it:dir){
               int x = i + it[0];
               int y = j + it[1];
              
               if(isValid(x,y,m,n)){
                   
                   if(dp[i][j] + grid[x][y] < dp[x][y]){
                       dp[x][y] = grid[x][y] + dp[i][j];
                       q.push({x,y});
                   }
               }
           }
        }
     
     return dp[m-1][n-1];
    }
};