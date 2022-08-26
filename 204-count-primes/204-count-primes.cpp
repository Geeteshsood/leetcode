class Solution {
public:
    
    int countPrimes(int n) {
        
        vector<int> isPrime(n,true);
        
        for(int num=2;num<=sqrt(n);num++){
            
            if(isPrime[num]){
                
                for(int i=num;num*i < n;i++){
                    int idx = num*i;
                    isPrime[idx] = false;
                    
                }
                
            }
            
        }
        
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
            }
        }
        
        return cnt;
    }
};