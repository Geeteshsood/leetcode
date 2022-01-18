// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	typedef long long ll;
	
	long long getCount(int N)
	{
		
	vector<vector<int>> digit(10,vector<int>());
	
	digit[0] = {0,8} , digit[1] = {1,2,4} , digit[2] = {2,1,5,3}, digit[3] = {3,2,6} , digit[4] = {4,1,5,7},
	digit[5] = {5,2,4,8,6} , digit[6] = {6,3,5,9} , digit[7] = {7,4,8} , digit[8] = {8,5,7,9,0}, digit[9] = {9,6,8};
	
	
	vector<vector<ll>> dp(N+1,vector<ll>(10));
	
	for(int i=0;i<10;i++){
	    dp[1][i] = 1;
	}
	
	for(int i=2;i<N+1;i++){
	    for(int j=0;j<10;j++){
	        for(auto &it:digit[j]){
	            dp[i][j] += dp[i-1][it];
	        }
	    }
	}
	
    ll sum = 0;
    for(int i=0;i<10;i++){
        sum += dp[N][i];
    }
	return sum;
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends