class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(),idx = -1;
        
        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                idx = i-1;
                break;
            }
        }
        
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        int temp = -1 , mini = INT_MAX;
        
        for(int i=n-1;i>idx;i--){
            if(nums[i] > nums[idx] && nums[i] < mini){
                mini = nums[i];
                temp = i;
            }
        }
        
        swap(nums[idx],nums[temp]);
        
        reverse(nums.begin() + idx+1,nums.end());
        
    }
};