// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int isValid(vector<vector<int>> board){
       
        vector<int> row(10),col(10);
        vector<vector<int>> grid(3,vector<int>(3));
        
          for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                 if(board[i][j] == 0)continue;
                
                 int digit = board[i][j];
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

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends