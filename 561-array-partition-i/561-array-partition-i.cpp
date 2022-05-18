class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size() , sum = 0;
        
        for(int i=n-1;i>=0;i=i-2){
            int val = min(nums[i],nums[i-1]);
            sum += val;
        }
        
      return sum;  
    }
};