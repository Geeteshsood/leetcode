class Solution {
public:
    int nthUglyNumber(int n) {
        
       vector<int> dp(n);
       dp[0] = 1;
       int i = 0 , j = 0 , k = 0;
        
       for(int p=1;p<n;p++){
           
           int x = 2*dp[i] , y = 3*dp[j] , z = 5*dp[k];
           
           int val = min({x,y,z});
           
           if(x == val)i++;
           if(y == val)j++;
           if(z == val)k++;
           
           dp[p] = val;
       }
        
     return dp[n-1]  ; 
    }
};