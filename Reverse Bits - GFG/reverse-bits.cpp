// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long n) {
        
         n = ((n & 0x0000ffff)<<16) | ((n & 0xffff0000)>>16);
          n = ((n & 0x00ff00ff)<<8) | ((n & 0xff00ff00)>>8);
          n = ((n & 0x0f0f0f0f)<<4) | ((n & 0xf0f0f0f0)>>4);
          n = ((n & 0x33333333)<<2) | ((n & 0xcccccccc)>>2);
          n = ((n & 0x55555555)<<1) | ((n & 0xaaaaaaaa)>>1);
        
        return n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends