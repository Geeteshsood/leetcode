// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    typedef long long ll;
    
    ll gcd(ll a,ll b){
        
        if(b == 0)return a;
        
        return gcd(b,a%b);
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
       
        ll x = gcd(B,A%B);
        
        return {(A*B)/x,x};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends