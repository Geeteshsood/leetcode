// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
typedef long long ll;
class Solution{
    public:
    long long maximumAmount(int nums[], int n){

        vector<vector<ll>> dp(n,vector<ll>(n)) ,sum(n,vector<ll>(n));
        
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(j>0)sum[i][j] = (ll)nums[j] + sum[i][j-1];
               else sum[0][0] = (ll)nums[0];
            }
        }
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                if(g == 0){
                    dp[i][j] = nums[i];
                    continue;
                }
                
                ll x = (ll)nums[j] + sum[i][j-1] - dp[i][j-1];
                ll y = (ll)nums[i] + sum[i+1][j] - dp[i+1][j];
                
                dp[i][j] = max(x,y);
            }
        }

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