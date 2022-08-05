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
        
        // cout<<idx<<endl;
        if(idx != -1){
            int val = INT_MAX , temp = -1;
            for(int i=n-1;i>idx;i--){
                if(nums[i] > nums[idx] && nums[i] < val){
                      val = nums[i];
                      temp = i;
                }
            }
            // cout<<temp<<endl;
            swap(nums[idx],nums[temp]);
        }
        
        
        reverse(nums.begin() + idx + 1,nums.end());
        
    }
};