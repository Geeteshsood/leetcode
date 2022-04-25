class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        stack<int> st;
        vector<int> left(n);
        
        for(int i=0;i<n;i++){
            
            while(st.size() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            
            if(st.size()){
                left[i] = st.top();
            }
            else left[i] = -1;
            
            st.push(i);
        }
        
        while(st.size())st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            
            if(st.size()){
                if(left[i] != -1)return true;
            }
          
            st.push(i);
        }
        
      return false;  
    }
};