// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int setAllRangeBits(int N , int L , int R) {
        
        int n = 0;
        n = n | (1<<R);
        
        n = n-1;
        
        n = n ^ (1<<(L-1));
        n = n + 1;
        
        N = N | n;
        
        return N;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.setAllRangeBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends