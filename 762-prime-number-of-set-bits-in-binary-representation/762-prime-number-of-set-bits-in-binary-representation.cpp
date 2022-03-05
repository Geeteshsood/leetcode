class Solution {
public:
    
    bool checkprime(int n){
     return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19;
    }
    
    int countPrimeSetBits(int left, int right) {
        
        int cnt = 0;
        
        for(int num=left;num<=right;num++){
            
            int bit = __builtin_popcount(num);
            
            if(checkprime(bit))cnt++;
            
        }
       
        return cnt;
    }
};