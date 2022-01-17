class Solution {
public:
    
    int dp[50][50][50][50];
    bool flag = false;
    
    bool isValid(int i,int j,int n){
        return i < 0 || j < 0 || i >= n || j >= n;
    }
    
    int find(int r1,int c1,int r2,int c2,vector<vector<int>> &grid){
        
      int n = grid.size();
        
      if(isValid(r1,c1,n) || isValid(r2,c2,n) || grid[r1][c1] == -1 || grid[r2][c2] == -1)return INT_MIN;
        
      int x = grid[r1][c1] , y = grid[r2][c2];
        
      if(dp[r1][c1][r2][c2] != -1)return dp[r1][c1][r2][c2];
        
      int val = 0;
        
      if(r1 == r2 && c1 == c2){
          if(r1 == n-1 && c1 == n-1)return grid[r1][c1];
          val = x;
      }
      else val = x + y;
        
      int dd = find(r1+1,c1,r2+1,c2,grid);
      int rr = find(r1,c1+1,r2,c2+1,grid);
      int dr = find(r1+1,c1,r2,c2+1,grid);
      int rd = find(r1,c1+1,r2+1,c2,grid); 
        
      int res = max({dd,rr,dr,rd});
        
      return dp[r1][c1][r2][c2] = val + res;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        
        int x = find(0,0,0,0,grid);
        
        if(x<0)return 0;
            
        return x;
    }
};