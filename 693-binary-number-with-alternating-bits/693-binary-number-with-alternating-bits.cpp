class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int x = n & 1;
        n = n>>1;
        
        while(n){
            
           int y = n & 1;
            
           if(x^y)x = y;
           else return false;
               
           n = n>>1;
        }
        
      return true;  
    }
};