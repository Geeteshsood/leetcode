// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    typedef long long int ll;
    
    long long int bitsAreInAltOrder(long long int n){
    
        ll x = n;
        n = n>>1;
        
        n = n^x;
        
        n = n + 1;
        
        ll rsb = n & -n;
    
        return rsb == n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.bitsAreInAltOrder(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends