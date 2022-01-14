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
k = 3.

 0  1  2  3  4  5  
 ----------------
    -------------
       ----------
          -------
    
 0  1  2  3  4  5  
 -------------
    ----------
       -------
        
agar hum 4 se uska best mangege  
uske paas >=3 size ka max subarray ka sum pada hoga jo 4 par end ho rahe hai.
    
us maximum me agar hum 5 add karde.
toh humare paas >=4 size ka max subarray ka sum aa jayega jo 5 par end ho rahe hai.
    
isko hum 5 par end hone wale 3 size ke subarray ke sum ke saath compare kar lenge.
    
usse hum 5 par khatam hone wale >=3 size (or >=k ) subarray ka max sum mil jayenga.

*/

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
    
    long long int ans = dp[k-1];
    
    for(long long int i=k;i<n;i++){
        dp[i] = max(dp[i] , dp[i-1] + arr[i]);
        ans = max(ans,dp[i]);
    }
    
    
    
    
    return ans;
    
}