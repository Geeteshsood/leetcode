class Solution {
public:
    
    int find(int i,int d,vector<bool> &vis,vector<int> &nex,vector<int> &prev,vector<int> &dp){
        
        if(i < 0 || i >= vis.size() || vis[i])return INT_MIN;
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        vis[i] = true;
        
        int x = INT_MIN , y = INT_MIN;
        
        for(int j=i+1;j<=i+d;j++){
              if(nex[i] > j){
                 x = max(x , find(j,d,vis,nex,prev,dp));
              }
        }
        
        for(int j=i-1;j>=i-d;j--){
              if(prev[i] < j){
                  y = max(y , find(j,d,vis,nex,prev,dp));
              }
        }
        vis[i] = false;
        
        x = max(x,0),y = max(y,0);

        return dp[i] = 1 + max(x , y);
    }
    
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size() , ans = INT_MIN;
        
        vector<int> nex(n),prev(n);
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && arr[i]>arr[st.top()])st.pop();
            
            if(st.empty())nex[i] = n;
            else nex[i] = st.top();
            
            st.push(i);
        }
        
         while(st.size())st.pop();
        
         for(int i=0;i<n;i++){
            
            while(st.size() && arr[i]>arr[st.top()])st.pop();
            
            if(st.empty())prev[i] = -1;
            else prev[i] = st.top();
            
            st.push(i);
        }
        
        vector<bool> vis(n,false);
        vector<int> dp(n,-1);
        
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            
            int x = find(i,d,vis,nex,prev,dp);
            ans = max(ans,x);         
        }
        
       return ans; 
    }
};