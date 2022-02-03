class Solution {
public:
    
    int row[10],col[10],box[10];
    
    void generate(vector<vector<char>>& board){
         
        for(int i=0;i<9;i++){
            int rmask = 0 , cmask = 0;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.')rmask = rmask | (1<<(board[i][j] - '0'));
                if(board[j][i] != '.')cmask = cmask | (1<<(board[j][i] - '0'));
            }
            row[i] = rmask;
            col[i] = cmask;
        }
        
        int cnt = 0;
        for(int r=0;r<9;r+=3){
          for(int c=0;c<9;c+=3){ 
             int bmask = 0;
             for(int i=r;i<r+3;i++){
                 for(int j=c;j<c+3;j++){
                     if(board[i][j] != '.')bmask = bmask | (1<<(board[i][j] - '0'));
                 }
             }
             box[cnt] = bmask;
             cnt++;
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
            
        int k = 3*(r/3) + (c/3);
          
        for(int n=1;n<10;n++){
            
            bool flag = (row[r] & (1<<n)) || (col[c] & (1<<n)) || (box[k] & (1<<n)); // checking if bit is found
            
            if(!flag){
                
                row[r] ^= (1<<n);        // setting bit
                col[c] ^= (1<<n);
                box[k] ^= (1<<n);
                
                board[r][c] = n + '0';
                
                if(solve(r,c+1,board)){
                    return true;
                }
                
                board[r][c] = '.';
                
                row[r] ^= (1<<n);
                col[c] ^= (1<<n);          // unsetting bit.
                box[k] ^= (1<<n);
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(box,0,sizeof(box));
        
        generate(board);
        solve(0,0,board);
        
    }
};