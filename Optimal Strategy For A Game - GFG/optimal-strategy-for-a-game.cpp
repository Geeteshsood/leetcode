// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
typedef long long ll;
class Solution{
    public:
    long long maximumAmount(int nums[], int n){

        vector<vector<ll>> dp(n,vector<ll>(n));
        
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(j>0)dp[i][j] = (ll)nums[j] + dp[i][j-1];
               else dp[0][0] = (ll)nums[0];
            }
        }
        
        for(int g=1;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                dp[i][j] = max(dp[i][j] - dp[i][j-1],dp[i][j] - dp[i+1][j]);
            }
        };
        
     return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends