class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
           int n = nums.size();
           vector<int> v(32);
        
           for(int i=0;i<n;i++){
                int num = nums[i];
               
                for(int j=0;j<32;j++){
                    
                    if(num & (1<<j)){
                        v[j]++;
                    }
                    
                }
           }
        
           int val = 0;
        
           for(int j=0;j<32;j++){
                 if(v[j]%3!=0){
                     val += (1<<j);
                 }
           }
        
        return val; 
    }
};