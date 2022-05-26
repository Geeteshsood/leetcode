class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int counter = 0;
        
        while(n){
            
           int rsb = n & -n;
            
           n = n - rsb;
            
           counter++;
        }
        
        return counter;
    }
};