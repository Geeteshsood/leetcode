class Solution {
public:

    int row[10],col[10],d1[19],d2[19];
    int cnt = 0;
    
    bool check(int i,int j){
        
      return !(d1[i+j] || d2[9+i-j] || row[i] || col[j]);
        
    }
    
     void solve(int i,int j,int n,vector<vector<char>> &board){
      
     if(i == n){
         cnt++;
         return;
     }

      for(int j=0;j<n;j++){
         
       if(check(i,j)){
             
             d1[i+j] = 1 , d2[9 + i-j] = 1 , row[i] = 1 , col[j] = 1;
             board[i][j] = 'Q';
             // set bit
             
             solve(i+1,j,n,board);
             
             board[i][j] = '.';
             d1[i+j] = 0 , d2[9 + i-j] = 0 , row[i] = 0 , col[j] = 0;
             // clear bit.
         }
      }   
        
    }
    
    
    int totalNQueens(int n) {
        
         vector<vector<char>> board(n,vector<char>(n,'.'));
         solve(0,0,n,board);
        
        return cnt;
    }
};