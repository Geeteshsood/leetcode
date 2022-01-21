class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
       int m = primes.size();
       vector<int> pointer(m,0);
       vector<int> dp(n);
       dp[0] = 1;
    
       for(int i=1;i<n;i++){
           
           int val = INT_MAX;
           for(int j=0;j<m;j++){
                val = min(val , primes[j]*dp[pointer[j]]);
           }
           
           dp[i] = val;
           
           for(int j=0;j<m;j++){
                if(primes[j]*dp[pointer[j]]==val)
                    pointer[j]++;
           }
       }
       
     return dp[n-1];
    }
};