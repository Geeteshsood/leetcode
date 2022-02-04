class Solution {
public:
    
     int col=0,d1=0,d2=0;
             
     vector<vector<string>> ans;     
    
     void print(int n,vector<vector<char>> &board){
             
         vector<string> v;   
         
         for(int i=0;i<n;i++){
             string str;    
             for(int j=0;j<n;j++){
                 str += board[i][j];
             } 
            v.push_back(str);     
         } 
         
        ans.push_back(v);
     } 
    
    bool check(int i,int j){
        
        bool x = d1 & (1<<(i+j));
        bool y = d2 & (1<<(9 + i-j));
        bool z = col & (1<<(j));
      
      return !(x || y || z);
    }
    
     void solve(int i,int j,int n,vector<vector<char>> &board){
      
     if(i == n){
         print(n,board);
         return;
     }

      for(int j=0;j<n;j++){
         
       if(check(i,j)){               // checking bit is on or off.
             
              d1 |= (1<<(i+j));
              d2 |= (1<<(9 + i-j));  // bit set
             col |= (1<<(j));
                 
             board[i][j] = 'Q';
             
             solve(i+1,j,n,board);
             
             board[i][j] = '.';
             
              d1 ^= (1<<(i+j));
              d2 ^= (1<<(9 + i-j));   // bit unset
             col ^= (1<<(j));
         }
      }   
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
           
           vector<vector<char>> board(n,vector<char>(n,'.'));
           solve(0,0,n,board);
        
        return ans;
    }
};