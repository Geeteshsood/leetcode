class Solution {
public:
    
     vector<int> nextGreaterElement(vector<int>& nums2) {
        
        int n = nums2.size();
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && nums2[i] >= st.top()){
                st.pop();
            }
            
            if(st.size())ans[i] = st.top();
            else ans[i] = -1;
            
            st.push(nums2[i]);
        }

           vector<int> res(ans.begin(),ans.begin()+n/2);
         
         return res;
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> v;
        int n = nums.size();
        
        for(int i=0;i<2*n;i++){
            v.push_back(nums[i%n]);
        }
        
        return nextGreaterElement(v);
    }
};