// 5 3 4 6 7 8 1 9 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 2 3 4 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 . . 8 . 3 . . 1 
// 7 . . . 2 . . . 6 
// . 6 . . . . 2 8 . 
// . . . 4 1 9 . . 5 
// . . . . 8 . . 7 9 
class Solution {
public:
    
    bool isValid(int dig,int r,int c,vector<vector<char>> &board){
         // bool flag = false;
         // if(r >=3 && board[0][2] == '4' && board[1][1] == '7' && board[3][1] == '5' && board[3][3] == '7' && board[3][2] == '9' && board[3][7] == '2'){
         //     flag = true;
         // 
        
        // if(flag)cout<<r<<" , "<<c<<endl;
        
        char val = dig + '0';
    
        for(int i=0;i<9;i++){
             
                 // if(flag){
                 //     cout<<board[r][i]<<" "<<board[i][c]<<" "<<val<<endl;
                 // }
             
            if(board[r][i] == val || board[i][c] == val)return false;
        }
        
        int x = 3*(r/3) , y = 3*(c/3);
        
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool find(int r,int c,vector<vector<char>>& board){
        
           if(r==8 && c==8)return true;
//         if(r >=3 && board[0][2] == '4' && board[1][1] == '7' && board[3][1] == '5' && board[3][3] == '7' && board[3][2] == '9' && board[3][7] == '2'){
            
//            for(int i=0;i<9;i++){
//                for(int j=0;j<9;j++){
//                    cout<<board[i][j]<<" ";
//                }
//                cout<<endl;
//            }
            
        
//            cout<<r<<" "<<c<<" *** "<<endl;
//         }
        
           if(c == 8)c=0,r++;
        
           // if(r >=3 && board[0][2] == '4' && board[1][1] == '7' && board[3][1] == '5' && board[3][3] == '7' && board[3][2] == '9' && board[3][7] == '2'){cout<<r<<" , "<<c<<" *** "<<endl;}
               // bool flag = true;
        
           for(int i=r;i<9;i++){
               for(int j=c;j<9;j++){
                   
                   if(board[i][j] != '.'){
                       if(j == 8)j=-1,i++;
                       if(i == 9)return true;
                       continue;
                   }
                   
                   // flag = false;
                   for(int dig=1;dig<10;dig++){
          
                       if(isValid(dig,i,j,board)){
                           
                           board[i][j] = dig + '0';
                           
                           if(find(i,j,board))return true;
                           
                           board[i][j] = '.';
                       }
                   }
                   return false;
               }
           }
        
      return true;  
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
          find(0,0,board);
         
    }
};