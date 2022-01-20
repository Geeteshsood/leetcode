class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size() , moves = 0;
        
        for(int i=n-1;i>0;i--){
             moves += nums[i] - nums[0];
        }
        
        return moves;
    }
};