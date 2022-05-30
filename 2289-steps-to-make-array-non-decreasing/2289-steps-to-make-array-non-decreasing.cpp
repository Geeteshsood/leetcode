class Solution {
public:
    typedef pair<int,int> pi;
    
    int totalSteps(vector<int>& nums) {
        
        int n = nums.size() , ans = 0;
        stack<pi> st;
        
        for(int i=n-1;i>=0;i--){
            
            int cnt = 0;
            
            while(st.size() && nums[i] > st.top().first){
                cnt = max(cnt+1,st.top().second);
                st.pop();
            }
            
            st.push({nums[i],cnt});
            ans = max(ans,cnt);
        }
        
      return ans;  
    }
};