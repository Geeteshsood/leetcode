class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size(),idx = 0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i] < 0)idx = -nums[i];
            else idx = nums[i];
            
            if(nums[idx] < 0)return idx;
            else nums[idx] = -nums[idx];
        }
        
        return -1;
    }
    
};