// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    #include<bits/stdc++.h>
    
    typedef long long ll;
    
    long long trappingWater(int arr[], int n){
       
        ll sum = 0;
        
        if(n==0)return 0;    
               
        vector<int> left(n);
        vector<int> right(n);    
               
        left[0]=0,right[n-1]=0; 
               
        for(int i=1;i<n;i++){
           left[i]=max(left[i-1],arr[i-1]);  
        }       
        
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i+1]);    
        }
               
        for(int i=0;i<n;i++){
            
          ll val=min(left[i],right[i]); 
          
          if(val>arr[i]){
              sum+=val-arr[i];
          } 
        }
            
       return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends