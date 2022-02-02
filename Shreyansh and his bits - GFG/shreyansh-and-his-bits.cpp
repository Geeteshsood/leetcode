// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    typedef long long ll;
    
    ll factorial(ll n,ll r){
       
      ll res = 1L;
      
      for (ll i = 0L; i < r; i++){
          
          res = res * (n-i);
          res = res / (i+1L);
          
    
          
      return res;
    }
    
    long long count(long long x) {
        
        ll ans = 0 , cnt = 0 , setbit = 0 , bit = (ll)1;
        
        for(ll i=(ll)0;i<(ll)64;i++){
            
           if(x & (bit<<i)){
               setbit++;
            //   cout<<i<<" "<<setbit<<endl;
               if(i)ans += factorial(i,setbit);
           }
        }
        
       return ans; 
    }
};

// { Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}  // } Driver Code Ends