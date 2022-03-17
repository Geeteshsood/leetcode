// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        
        int cnt = 0;
        
        for(int i=1;i<=sqrt(N);i++){
            if(i*i == N){
                cnt+=1;
            }
            else if(N%i == 0)cnt+=2;
        }
        
        return cnt == 2;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends