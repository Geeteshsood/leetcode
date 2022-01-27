class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> dq;
        
        dq.push_back(n-1);
        int val = 0;
        
        for(int i=n-2;i>=0;i--){

            if(dq.back() > i + k)dq.pop_back();

            nums[i] += nums[dq.back()];
            
            while(dq.size() && nums[i] > nums[dq.front()]){
                dq.pop_front();
            }
            
            dq.push_front(i);
        }

        return nums[0];
    }
};