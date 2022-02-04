// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

     int row[10],col[10],d1[19],d2[19];
    
     void print(int n,vector<vector<char>> &board,vector<vector<int>> &ans){
             
         vector<int> v;   
         
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(board[i][j] == 'Q'){
                     v.push_back(j+1);
                 }
             } 
         } 
         
        ans.push_back(v);
     } 
    
    bool check(int i,int j){
        
      return !(d1[i+j] || d2[9+i-j] || row[i] || col[j]);
        
    }
    
    void solve(int i,int j,int n,vector<vector<char>> &board,vector<vector<int>> &ans){
      
     if(i == n){
         print(n,board,ans);
         return;
     }

      for(int j=0;j<n;j++){
         
       if(check(i,j)){
             
             d1[i+j] = 1 , d2[9 + i-j] = 1 , row[i] = 1 , col[j] = 1;
             board[i][j] = 'Q';
             // set bit
             
             solve(i+1,j,n,board,ans);
             
             board[i][j] = '.';
             d1[i+j] = 0 , d2[9 + i-j] = 0 , row[i] = 0 , col[j] = 0;
             // clear bit.
         }
      }   
        
    }
    vector<vector<int>> nQueen(int n) {
        
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        
        
        vector<vector<int>> ans;  
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solve(0,0,n,board,ans);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends