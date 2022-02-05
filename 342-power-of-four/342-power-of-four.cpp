class Solution {
public:
    bool isPowerOfFour(int n) {
        
       if(n <= 0)return 0;
        
       int rsb = n & -n;
        
       if(n != rsb)return 0;
       
       for(int i=0;i<32;i++){
            if(n & (1 << i)){
                if(i%2 != 0)return 0;
            }
       }
      
      return 1;
        
    }
};