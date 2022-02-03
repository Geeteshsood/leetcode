class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> row(10),col(10);
        vector<vector<int>> grid(3,vector<int>(3));
        
          for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                 if(board[i][j] == '.')continue;
                
                 int digit = board[i][j] - '0';
                 int n = (1<<digit);
                
                 if((row[i] & n) || (col[j] & n) || (grid[i/3][j/3] & n))return false;
                
                 row[i] |= n;
                 col[j] |= n;
                
                 grid[i/3][j/3] |= n;
            }
        }
        
        
        return true;
    }
};