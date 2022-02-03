// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int nums[], int n, int X)  
{
        sort(nums,nums+n);
        
         for(int i=0;i<n;i++){
             
             for(int j=i+1;j<n;j++){
                 
                 int x = j+1 , y = n-1;
                 
                 while(x < y){
                     
                    int  left = nums[i] + nums[j];
                    int right = nums[x] + nums[y];
                    
                    if(left == X - right){
                        return true;
                    }
                     
                    if(left < X - right){
                        x++;
                    }
                    else{
                        y--;
                    }
                 } 
             }
         }
        
        return false;
}