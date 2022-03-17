// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int gcd(int x,int y){
        
        if(y == 0)return x;
        
        return gcd(y,x%y);
    }
    
    int rooms(int N, int M){
        
        int x = max(M,N) , y = min(M,N);
        
        int a = gcd(x,y);
        
        return (x/a) + (y/a);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        
        Solution ob;
        cout<<ob.rooms(N, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends