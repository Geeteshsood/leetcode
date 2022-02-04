class Solution {
public:
    
     unordered_map<int,int> d1,d2,row,col;
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
        
      return !(d1[i+j] || d2[i-j] || row[i] || col[j]);
        
    }
    
     void solve(int i,int j,int n,vector<vector<char>> &board){
      
     if(i == n){
         print(n,board);
         return;
     }
        
//       for(int i=0;i<n;i++){
//          for(int j=0;j<n;j++){
//              cout<<board[i][j]<<" ";
//          }
//           cout<<endl;
//      }
//            cout<<"**"<<endl;
        
      for(int j=0;j<n;j++){
         
         // cout<<d1[i+j]<<" "<<d2[i-j]<<" "<<row[i]<<" "<<col[j]<<endl;
                                                                 
       if(check(i,j)){
             
             d1[i+j] = 1 , d2[i-j] = 1 , row[i] = 1 , col[j] = 1;
             board[i][j] = 'Q';
             // set bit
             
             solve(i+1,j,n,board);
             
             board[i][j] = '.';
             d1[i+j] = 0 , d2[i-j] = 0 , row[i] = 0 , col[j] = 0;
             // clear bit.
         }
      }   
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
           
           vector<vector<char>> board(n,vector<char>(n,'.'));
           solve(0,0,n,board);
        
        return ans;
    }
};