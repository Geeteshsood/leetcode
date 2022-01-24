class Solution {
public:
    
typedef long long ll;    
    
    long long maxAlternatingSum(vector<int>& nums) {
        
        ll even = 0 , odd = nums[0];
        int n = nums.size();
        
        for(int i=1;i<n;i++){
            
            ll e = max(odd - (ll)nums[i] , even);
            ll o = max(even + (ll)nums[i] , odd);
            
            even = e , odd = o;
        }
        
     return max(even,odd);
    }
};