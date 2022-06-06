// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
typedef long long int ll;

    // j -> 0 to i
         
    // for any point     j + ctrlv + ctrlv + ctrlv ------;
  
    long long int optimalKeys(int n){
        
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        
        dp[0] = {0,1};
        
        for(int i=1;i<=n;i++){
    
            ll val = 0 , copy = 0;
            
            for(int j=0;j<i;j++){
                
                if(i-j > 2){
                 val = dp[j][0]*(i-j-1);
                 copy = dp[j][0];
                }
                else{
                  val = dp[j][0] + (i-j)*dp[j][1];
                  copy = dp[j][1];  
                }
                 
                if(val > dp[i][0]){
                    dp[i][0] = val;
                    dp[i][1] = copy;
                }
                else if(val == dp[i][0]){
                    dp[i][1] = max(dp[i][1],copy);
                }
            }
        }
        
        return dp[n][0];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends