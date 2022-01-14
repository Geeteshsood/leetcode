// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int k, int n) 
    {
        vector<vector<int>> dp(k+1,vector<int>(n+1));
        
        for(int f=1;f<n+1;f++)dp[1][f] = f;
            
        for(int e=2;e<k+1;e++){
            for(int f=1;f<n+1;f++){
                int ans = INT_MAX ,val = 0;
                
                int start = 1 , end = f;
                
                while(start <= end){
                     int mid = end - (end-start)/2;
                     int up = dp[e][f-mid] , down = dp[e-1][mid-1];
                    
                     if(up > down){
                         start = mid + 1;
                     }
                     else end = mid - 1;
                    
                     val = 1 + max(down , up);
                     ans = min(val,ans);
                }
                dp[e][f] = ans;
            }
        }
        
     return dp[k][n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends