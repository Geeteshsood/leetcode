// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  typedef long long int ll;
  
    long long int countBT(int h) { 
       
       ll mod = 1e9 + 7;
       vector<ll> dp(h+1,1);
       
       for(int i=2;i<=h;i++){
           
          dp[i] = ((dp[i-1]*dp[i-1])%mod + (2*dp[i-1]*dp[i-2])%mod)%mod;
           
       }
      
      return dp[h]; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends