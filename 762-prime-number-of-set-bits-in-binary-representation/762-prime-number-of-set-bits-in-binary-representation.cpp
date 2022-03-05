class Solution {
public:
    
    bool checkprime(int n){
        
        if(n == 1)return false;
        
        for(int i=2;i<n;i++){
            if(n%i == 0)return false;
        }
        
        return true;
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