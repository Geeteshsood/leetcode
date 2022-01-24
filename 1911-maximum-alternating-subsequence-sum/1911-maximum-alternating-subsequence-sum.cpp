class Solution {
public:
    
typedef long long ll;    
    
    long long maxAlternatingSum(vector<int>& nums) {
        
        ll even = 0 , odd = nums[0];
        
        for(auto &i : nums){
            
            odd = max(odd , even + (ll)i);
            even = odd - (ll)i;
        }
        
     return odd;
    }
};