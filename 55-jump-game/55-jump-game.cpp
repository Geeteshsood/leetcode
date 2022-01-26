class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxReach = nums[0];
        
        for(int i=1;i<=min(n-1,maxReach);i++){
            maxReach = max(maxReach,i+nums[i]);
        }

     return maxReach>=n-1;   
    }
};