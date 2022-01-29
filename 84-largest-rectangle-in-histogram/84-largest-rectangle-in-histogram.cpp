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
        
        stack<int> st2;
        
        for(int i=n-1;i>=0;i--){
            
            while(st2.size() && heights[i] <= heights[st2.top()]){
                st2.pop();
            }
            
            if(st2.empty())nex[i] = n;
            else nex[i] = st2.top();
            
            st2.push(i);
        }
        
        int val = 0 , ans = 0;
        
        for(int i=0;i<n;i++){
            val = (nex[i] - prev[i] - 1)*heights[i];
            ans = max(ans,val);
        }
        
     return ans;   
    }
};