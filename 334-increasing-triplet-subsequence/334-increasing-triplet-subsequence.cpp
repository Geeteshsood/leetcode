class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> left(n,INT_MAX);
        
        for(int i=1;i<n;i++){
            left[i] = min(left[i-1],nums[i-1]);
        }
        
        int val = INT_MIN;
        
        for(int i=n-2;i>0;i--){
            val = max(val,nums[i+1]);
            if(left[i] < nums[i] && val > nums[i]){
                return true;
            }
        }
        
        return false;
    }
};