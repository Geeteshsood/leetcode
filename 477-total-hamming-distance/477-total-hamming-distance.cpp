class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size(),cnt = 0 ;
        
        for(int bit=0;bit<32;bit++){
            
            int one = 0 , zero = 0;
            
            for(int i=0;i<n;i++){
                if(nums[i] & (1<<bit)){
                    one++;
                }
                else zero++;
            }
            
            cnt += one*zero;
            
        }
        
        return cnt;
    }
};