class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> lg(n) , rg(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            
            while(st.size() && height[i] >= height[st.top()]){
                st.pop();
            }
            
            if(st.size())lg[i] = st.top();
            else lg[i] = -1;
            
            st.push(i);
        }

        while(st.size())st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && height[i] > height[st.top()]){
                st.pop();
            }
            
            if(st.size())rg[i] = st.top();
            else rg[i] = n;
            
            st.push(i);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            if(lg[i] == -1 || rg[i] == n)continue;
            
            int h = min(height[lg[i]],height[rg[i]]) - height[i];
            int width = rg[i]-lg[i]-1;
            
            int val = h*width;
            // cout<<i<<" "<<val<<endl;
            ans += val;
        }
        
        return ans;
    }
};