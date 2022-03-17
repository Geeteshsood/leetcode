// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int isPrime(int N){

        if(N == 1)return false;
        
        if(N == 2 || N == 3)return true;
        
        for(int i=2;i*i<=N;i++){
             if(N%i == 0)return false;
        }
        
        return true;
    }
  
    vector<int> primeRange(int M, int N) {
        
        vector<int> ans;
        
        for(int i=M;i<=N;i++){
            if(isPrime(i)){
                ans.push_back(i);
            }
        }
        
      return ans;  
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends