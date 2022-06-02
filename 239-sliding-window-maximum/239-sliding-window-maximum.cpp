class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
          int n = nums.size();
          deque<int> dq;
          vector<int> ans;
        
          for(int i=0;i<n;i++){
              
              while(dq.size() && nums[i] >= nums[dq.back()]){
                  dq.pop_back();
              }
              
              while(dq.size() && i-k >= dq.front()){
                  dq.pop_front();
              }
              
              dq.push_back(i);
              
              if(i >= k-1)ans.push_back(nums[dq.front()]);
          }
        
        return ans;
    }
};