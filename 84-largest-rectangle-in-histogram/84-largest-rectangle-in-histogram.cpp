class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size() , ans = 0;
        vector<int> lse(n+1);
        
        stack<int> st;
        
        for(int i=0;i<=n;i++){
            
            while(st.size() && (i == n || heights[i] <= heights[st.top()])){
                
                  int val = (i - lse[st.top()]-1)*heights[st.top()];
                  // cout<<i<<" "<<lse[st.top()]<<" "<<st.top()<<endl;
                  ans = max(ans,val);
                
                  st.pop();
            }
            
            if(st.size())lse[i] = st.top();
            else lse[i] = -1;
            
            st.push(i);
        }

        return ans;
    }
};