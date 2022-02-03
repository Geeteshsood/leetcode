class Solution {
public:
    
    int row[10],col[10],grid[3][3];
    
    void generate(vector<vector<char>>& board){
         
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                 if(board[i][j] == '.')continue;
                
                 int digit = board[i][j] - '0';
                
                 row[i] |= (1<<digit);
                 col[j] |= (1<<digit);
                
                 grid[i/3][j/3] |= (1<<digit);
            }
        }
    }
    
    bool solve(int r,int c,vector<vector<char>> &board){
        
        if(c == 9){
            if(r == 8)return true;
            
            return solve(r+1,0,board);
        }
        
        if(board[r][c] != '.'){
            return solve(r,c+1,board);
        }
            
        for(int n=1;n<10;n++){
            
      bool flag = (row[r] & (1<<n)) || (col[c] & (1<<n)) || (grid[r/3][c/3] & (1<<n)); // checking if bit is found
            
            if(!flag){
                
                row[r] ^= (1<<n);        // setting bit
                col[c] ^= (1<<n);
                grid[r/3][c/3] ^= (1<<n);
                
                board[r][c] = n + '0';
                
                if(solve(r,c+1,board)){
                    return true;
                }
                
                board[r][c] = '.';
                
                row[r] ^= (1<<n);
                col[c] ^= (1<<n);          // unsetting bit.
                grid[r/3][c/3] ^= (1<<n);
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(grid,0,sizeof(grid));
        
        generate(board);
        solve(0,0,board);
        
    }
};