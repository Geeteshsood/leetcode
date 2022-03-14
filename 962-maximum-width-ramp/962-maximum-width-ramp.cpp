class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.empty() || (nums[i] > nums[st.top()]))st.push(i);
        }
        
        int reach = 0;
        
        for(int i=0;i<n-reach;i++){
            
            while(st.size() && nums[i] <= nums[st.top()]){
                reach = max(reach, st.top() - i);
                st.pop();
            }
            
        }
       
        return reach;
    }
};