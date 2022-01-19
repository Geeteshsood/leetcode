// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int find(int i,int arr[],vector<int> &candy){
        
        if(i == candy.size()-1){
            if(arr[i] > arr[i-1])return candy[i] = candy[i-1] + 1;
            return candy[i] = 1;
        }
        
        int a = arr[i-1] , b = arr[i] , c = arr[i+1];
        
        if(b == a && b <= c){
            candy[i] = 1;
            find(i+1,arr,candy);
        }
        else if(b == a){
          candy[i] = 1 + find(i+1,arr,candy);
        }
        else if(b > a && b > c){
          candy[i] = 1 + max(candy[i-1],find(i+1,arr,candy));
        }
        else if(b<a && b<c){
            candy[i] = 1;
            find(i+1,arr,candy);
        }
        else if( b<a && b>c){
            candy[i] = 1 + find(i+1,arr,candy);
        }
        else{
            candy[i] = 1 + candy[i-1];
            find(i+1,arr,candy);
        }
     
     return candy[i]; 
    }
    
    int offerings(int N, int arr[]){
        
        if(N == 1)return 1;
        
        vector<int> candy(N);
        
        if(arr[0] <= arr[1]){
            candy[0] = 1;
            find(1,arr,candy);
        }
        else candy[0] = 1 + find(1,arr,candy);
        
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += candy[i];
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