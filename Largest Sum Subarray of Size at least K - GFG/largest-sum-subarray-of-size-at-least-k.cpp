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


long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{
    
    long long int sum = 0;
    vector<long long int> dp(n);
    
    for(long long int i=0;i<k;i++){
        sum+=arr[i];
    }
    
    dp[k-1] = sum;
    for(long long int i=k;i<n;i++){
        sum += arr[i] - arr[i-k];
        dp[i] = sum;
    }
    
    for(long long int i=k;i<n;i++){
        dp[i] = max(dp[i] , dp[i-1] + arr[i]);
    }
    
    long long int ans = INT_MIN;
    for(long long int i=k-1;i<n;i++){
        ans = max(ans,dp[i]);
    }
    
    return ans;
    
}