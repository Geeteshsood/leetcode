// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        
     
          vector<int> res;
        
          int r1 = 0 , r2 = r-1 , c1 = 0 , c2 = c-1;
          
          while(r1 <= r2 &&  c1 <= c2){
              
              for(int j=c1;j<=c2;j++){
                //   cout<<mat[r1][j]<<" ";
                  res.push_back(mat[r1][j]);
              }
            //   cout<<endl;
              for(int i=r1+1;i<=r2-1;i++){
                //   cout<<mat[i][c2]<<" ";
                  res.push_back(mat[i][c2]);
              }
            //  cout<<endl;
              if(r1 != r2){
              
                for(int j=c2;j>=c1;j--){
                    // cout<<mat[r2][j]<<" ";
                    res.push_back(mat[r2][j]);
                }
              }
            //   cout<<endl;
              
              if(c1 != c2){
              for(int i=r2-1;i>r1;i--){
                //   cout<<mat[i][c1]<<" ";
                  res.push_back(mat[i][c1]);
              }
    // cout<<endl;
              }
              r1++,c1++,c2--,r2--;
          }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends