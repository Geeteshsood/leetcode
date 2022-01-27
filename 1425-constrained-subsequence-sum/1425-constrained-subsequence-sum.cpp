class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int ans = nums[n-1];
        
        deque<int> dq;
        dq.push_back(n-1);
        
        for(int i=n-2;i>=0;i--){
            
            if(dq.back() > i + k){
                dq.pop_back();
            }
            
            nums[i] = max(nums[i] , nums[i] + nums[dq.back()]);
            
            while(dq.size() && nums[i] > nums[dq.front()]){
                dq.pop_front();
            }
            
            dq.push_front(i);
            
            ans = max(ans,nums[i]);
        }
        
        return ans;
    }
};