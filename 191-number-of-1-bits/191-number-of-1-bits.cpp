class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int cnt = 0;
        
        while(n){
            
            int rsb = n & -n;
            n = n - rsb;
            cnt++;
            
        }
      
        return cnt;
    }
};