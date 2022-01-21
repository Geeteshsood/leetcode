// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	#define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
       vector<ull> dp(n);
       dp[0] = 1;
       ull i = 0 , j = 0 , k = 0;
        
       for(ull p=1;p<n;p++){
           
           ull x = 2*dp[i] , y = 3*dp[j] , z = 5*dp[k];
           
           ull val = min({x,y,z});
           
           if(x == val)i++;
           if(y == val)j++;
           if(z == val)k++;
           
           dp[p] = val;
       }
        
     return dp[n-1]  ; 
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends