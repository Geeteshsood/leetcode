class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size() , mid = n/2,val = 0;
        sort(nums.begin(),nums.end());
        
        
        if(n%2 == 0){
            val = (nums[mid-1] + nums[mid])/2;
        }
        else{
            val = nums[mid];
        }
        
        int ans = 0;
        
        for(auto &i : nums){
            ans += abs(i - val);
        }
        
        return ans;
    }
};