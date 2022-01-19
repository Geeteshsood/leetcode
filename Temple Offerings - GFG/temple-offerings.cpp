// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int offerings(int n, int arr[]){
        
        vector<int> left(n),right(n);
        
        left[0] = 1;
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                left[i] = 1 + left[i-1];
            }
            else left[i] = 1;
        }
        
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                right[i] = 1 + right[i+1];
            }
            else right[i] = 1;
        }
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += max(left[i],right[i]);
        }
      
      return sum;  
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.offerings(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends