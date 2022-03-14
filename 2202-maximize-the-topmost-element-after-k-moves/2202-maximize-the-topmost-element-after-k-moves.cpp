class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int n = nums.size() , val = 0;

        if(k%2 == 1  && n == 1)return -1;
        
        if(k == 1)return nums[1];

        for(int i=0;i<min(k-1,n);i++){
            val = max(val,nums[i]);
        }

        if(k < n){
           val = max(val,nums[k]) ;
        }
        
        return val;
    }
};