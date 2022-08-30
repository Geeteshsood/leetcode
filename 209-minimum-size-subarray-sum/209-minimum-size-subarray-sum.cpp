class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        
        int len = INT_MAX;
        
        int i = 0,j = 0, sum = 0;
        
        while(i < n){
            
            sum += nums[i];
            
            while(j <= i && sum >= target){
                sum -= nums[j];
                len = min(len , (i-j+1));
                j++;
            }
            
            i++;
        }
        
        if(len == INT_MAX)len = 0;
        
        return len;

    }
};