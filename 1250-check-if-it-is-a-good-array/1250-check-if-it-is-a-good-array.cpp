class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        
        int n = nums.size();
        int gcd1 = nums[0];
        
        for(int i=1;i<n;i++){
            gcd1 = gcd(gcd1,nums[i]);
        }
        
        return gcd1 == 1;
    }
};