class Solution{
public:
    
    int find(int i,vector<vector<int>> &graph,int mask,vector<vector<int>> &dp){
        
        int n = graph.size();
        
        mask = mask|(1<<i);

        if(mask == ((1<<n)-1))return 0;
            
        if(dp[i][mask] > 0){
            return dp[i][mask];
        }
        
        if(dp[i][mask] == -1){
            dp[i][mask] = 0;
        }
        else return INT_MAX;
        
        int ans = INT_MAX;
        
        for(auto &itr : graph[i]){
            
            int val = find(itr,graph,mask,dp);
            ans = min(ans,val);
        }

        if(ans == INT_MAX){
            dp[i][mask] = -1;
            return ans;
        }
        
        return dp[i][mask] = ans + 1;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size() , ans = INT_MAX;
        // vector<vector<int>> dp(n,vector<int>(1<<n,-1));
        
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(n,vector<int>(1<<n,-1));
           int x = find(i,graph,0,dp);
           // cout<<x<<endl;
           ans = min(ans,x);
        }
        
        return ans;
    }
};