// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int find(int e,int f,vector<vector<int>> &dp){
        
       if(dp[e][f] != -1){
           return dp[e][f];
       }
        
       if(f == 1)return dp[e][f] = 1;
       else if(f == 0)return dp[e][f] = 0;
       else if(e == 1)return dp[e][f] = f;
        
       int ans = INT_MAX , val = 0;
        
       for(int k=1;k<=f;k++){
           int x = 1 + find(e-1,k-1,dp);
           int y = 1 + find(e,f-k,dp);
         
           val = max(x,y);
           ans = min(ans,val);
       }
        
       return dp[e][f] = ans;
    }
    int eggDrop(int e, int n) 
    {
        vector<vector<int>> dp(e+1,vector<int>(n+1,-1));
        
        return find(e,n,dp);
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