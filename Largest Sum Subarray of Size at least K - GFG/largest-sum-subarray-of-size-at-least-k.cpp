// { Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
 this is 2 nd approach pepcoding channel
  
 pepcoding.
 
 
 
*/

long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{
    
    long long int val = 0 , sum = 0;
    vector<long long int> dp(n);
    
    dp[0] = max(val,arr[0]);
    for(long long int i=1;i<n;i++){
        dp[i] = max(val,arr[i] + dp[i-1]);
    }
    
    for(long long int i=0;i<k;i++){
        sum += arr[i];
    }
    
    long long int ans = sum;
    
    for(long long int i=k;i<n;i++){
        sum += arr[i] - arr[i-k];
        ans = max(ans,dp[i-k] + sum);
    }

    return ans;
    
}