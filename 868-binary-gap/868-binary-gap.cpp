class Solution {
public:
    int binaryGap(int n) {
        
         int ans = 0,prev = INT_MAX;
        
         while(n){
             int rsb = n & -n;
             n = n - rsb;
             int i = log2(rsb);
             int diff = i - prev;
             ans = max(ans,diff);
             prev = i;
         }       
     
        return ans;
    }
};