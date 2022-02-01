class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
      
        int val = 0;
        
        for(int j=0;j<32;j++){
           
           int cnt = 0;
            
           for(int i=0;i<n;i++){
               
                if(nums[i] & (1<<j)){
                       cnt++;
                }
           }
            
            if(cnt%3){
               val += (1<<j);
            } 
        }
        
        return val; 
    }
};