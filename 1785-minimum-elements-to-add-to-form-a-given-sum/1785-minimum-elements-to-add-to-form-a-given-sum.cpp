class Solution {
public:
    typedef long long ll;
    
    int minElements(vector<int>& nums, int limit, int goal) {
        
        ll n = nums.size() , sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        ll rem = goal - sum;
        
        long double x = (long double)abs(rem)/(long double)limit;
        
        int y = ceil(x);
        
        return y;
        
    }
};