class Solution {
public:

    int countPrimeSetBits(int left, int right) {
        
        unordered_set<int> prime{2,3,5,7,11,13,17,19};
        int cnt = 0;
        
        for(int num=left;num<=right;num++){
            
            int bit = __builtin_popcount(num);
            
            if(prime.find(bit) != prime.end())cnt++;
            
        }
       
        return cnt;
    }
};