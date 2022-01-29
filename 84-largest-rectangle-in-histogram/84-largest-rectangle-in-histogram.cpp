class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(-1);
        
        int n = heights.size();
        int ans = INT_MIN , leftsmall = 0;
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            
            while(st.size() && heights[i] < heights[st.top()]){
                
              int h = heights[st.top()];
              st.pop();
                
              if(st.size())leftsmall = st.top();
              else leftsmall = -1;
                
              ans = max(ans,(i-leftsmall-1)*h);
                
            }
           
            st.push(i);
        }
        
     return ans;   
    }
};