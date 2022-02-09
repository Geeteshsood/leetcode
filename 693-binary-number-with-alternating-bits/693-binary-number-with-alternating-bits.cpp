class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int x = n;
        n = n>>1;
        
        n = n^x;
        
        if(n == 2147483647)return true;
        
        n = n & (n + 1);
        
      return n == 0;  
    }
};