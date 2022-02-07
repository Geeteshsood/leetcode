class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        
        for(int i=0,j=31;i<16;i++,j--){
            
            bool seti = n & (1 << i);
            bool setj = n & (1 << j);
            
            if(seti){
                n = n | (1<<j);
            }
            else n = n & ~(1<<j);
            
            if(setj){
                n = n | (1<<i);
            }
            else n = n & ~(1<<i);
        }
        
        return n;
    }
};