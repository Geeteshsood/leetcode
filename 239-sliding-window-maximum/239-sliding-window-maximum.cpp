class Solution {
public:
    typedef pair<int,int> pi;
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
          int n = nums.size();
          deque<pi> dq;
          vector<int> ans;
        
          for(int i=0;i<n;i++){
              
              while(dq.size() && nums[i] > dq.back().first){
                  dq.pop_back();
              }
              
              while(dq.size() && i-k >= dq.front().second){
                  dq.pop_front();
              }
              
              dq.push_back({nums[i],i});
              
              if(i >= k-1)ans.push_back(dq.front().first);
          }
        
        return ans;
    }
};