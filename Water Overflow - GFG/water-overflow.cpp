// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int k, int r, int c) {
        
        if(r > k)return 0;
        
        vector<vector<double>> dp(k,vector<double>(k));
        
        dp[0][0] = (double)k;
        
        for(int i=0;i<k;i++){
            bool flag = true;
            for(int j=0;j<k;j++){
                if(dp[i][j]<=1)continue;
                
                flag = false;
                double rem = dp[i][j]-(double)1;
                dp[i][j] = (double)1;
                dp[i+1][j] += rem /2;
                dp[i+1][j+1] += rem/2;
            }
            if(flag)break;
        }
        
        return dp[r-1][c-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout <<setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}  // } Driver Code Ends