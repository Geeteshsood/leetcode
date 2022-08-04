class Solution {
public:
    typedef long long ll;
    
    int minElements(vector<int>& nums, int limit, int goal) {
        
        ll n = nums.size() , sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        ll rem = abs(goal - sum);
        
        return (rem + limit - 1)/limit;
        
    }
};