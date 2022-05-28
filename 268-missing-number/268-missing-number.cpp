class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size() , sum = 0;
        
        int total = (n*(n+1))/2;
        
        for(auto &i : nums){
            sum += i;
        }
        
        return total - sum;
    }
};