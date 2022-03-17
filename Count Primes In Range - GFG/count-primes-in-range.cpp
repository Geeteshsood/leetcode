// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int countPrimes(int L, int R) {
        
        vector<bool> isPrime(R+1,true);
        
        isPrime[0] = false , isPrime[1] = false;
        
        for(int i=2;i*i<=R;i++){
            
            if(isPrime[i]){
                for(int j=i*i;j<=R;j+=i){
                    isPrime[j] = false;
                }
            }
            
        }
        
        int cnt = 0;
        
        for(int i=L;i<=R;i++){
            if(isPrime[i]){
                cnt++;
            }
        }
        
      return cnt; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}  // } Driver Code Ends