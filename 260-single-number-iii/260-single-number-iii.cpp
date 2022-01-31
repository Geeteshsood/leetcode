class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        int Xor = 0;
        
        for(auto &i : nums){
            Xor = Xor^i;
        }
        
        int cnt = 0;
        
        while(Xor){
            
            if(Xor & 1 == 1){
                break;
            }
            
            Xor = Xor>>1;
            cnt++;
        }
        
        int Xor1 = 0 , Xor2 = 0;
        
        for(auto &i : nums){
            
            if(i & (1<<cnt)){
                Xor1 = Xor1^i;
            }
            else {
                Xor2 = Xor2^i;
            }
        }
        
      return {Xor1,Xor2} ;
    }
};