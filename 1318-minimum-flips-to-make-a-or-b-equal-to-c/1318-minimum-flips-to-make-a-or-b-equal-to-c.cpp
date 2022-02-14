class Solution {
public:
    
    int minFlips(int a, int b, int c) {
        
        int x = (a&b);
        int y =  x&c;
        
        int cnt = __builtin_popcount(x) - __builtin_popcount(y);
        
        cnt += __builtin_popcount(((a|b)^c));
        
        return cnt;
    }
};