// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
    
        int n = s.length();
        
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int g=1;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);
            }
        }
     
        return dp[0][n-1];
    
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends