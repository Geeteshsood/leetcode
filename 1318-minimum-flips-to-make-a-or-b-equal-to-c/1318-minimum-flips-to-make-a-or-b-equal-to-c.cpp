class Solution {
public:
    
    int minFlips(int a, int b, int c) {
        
        int cnt = 0;
        
        for(int i=0;i<32;i++){
            
           bool f1 = a & (1<<i);
           bool f2 = b & (1<<i);
           bool f3 = c & (1<<i);
            
           if((f1 && f2) && !f3)cnt += 2;
           else if((f1 || f2) && !f3)cnt += 1;
           else if((!f1 && !f2) && f3)cnt += 1;
            
        }
        
        return cnt;
    }
};