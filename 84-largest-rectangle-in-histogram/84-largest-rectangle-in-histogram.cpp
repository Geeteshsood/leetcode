class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> lse(n) , rse(n);
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            
            while(st.size() && heights[i] <= heights[st.top()]){
                  st.pop();
            }
            
            if(st.size())lse[i] = st.top();
            else lse[i] = -1;
            st.push(i);
        }
        
        while(st.size())st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && heights[i] <= heights[st.top()]){
                  st.pop();
            }
            
            if(st.size())rse[i] = st.top();
            else rse[i] = n;
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<lse[i]<<" "<<rse[i]<<endl;
        // }
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int val = (rse[i]-lse[i]-1)*heights[i];
            
            ans = max(ans,val);
        }
        
        return ans;
    }
};