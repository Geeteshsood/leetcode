class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int ans = 0 , width = 0;
        
        stack<int> st;
        
        for(int i=0;i<=n;i++){
            
            while(st.size() && (i == n || heights[i] <= heights[st.top()]) ){
                
              int h = heights[st.top()];
              st.pop();
                
              if(st.size())width = i - st.top() - 1;
              else width = i;
                
              ans = max(ans,width*h);
                
            }
           
            st.push(i);
        }
        
     return ans;   
    }
};