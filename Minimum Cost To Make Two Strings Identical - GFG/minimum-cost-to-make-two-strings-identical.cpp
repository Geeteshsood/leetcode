// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    int m = X.length() , n = Y.length();
    
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        
        for(int i=1;i<m+1;i++){
            dp[i][0] = costX + dp[i-1][0];
        }
        for(int j=1;j<n+1;j++){
            dp[0][j] = costY + dp[0][j-1];
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(costX + dp[i-1][j] , costY + dp[i][j-1]);
                }
            }
        }
        
      return dp[m][n];
	}
  

};
	

// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends