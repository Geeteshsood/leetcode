class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> prev(n),nex(n);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            
            while(st.size() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            
            if(st.empty())prev[i] = -1;
            else prev[i] = st.top();
            
            st.push(i);
        }
        
        while(st.size())st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            
            if(st.empty())nex[i] = n;
            else nex[i] = st.top();
            
            st.push(i);
        }
        
        int val = 0 , ans = 0;
        
        for(int i=0;i<n;i++){
            val = (nex[i] - prev[i] - 1)*heights[i];
            ans = max(ans,val);
        }
        
     return ans;   
    }
};