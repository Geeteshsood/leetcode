class Solution {
public:
    
    int dp[201][201];
    
    int dfs(int i,int j,int x,int y,vector<vector<int>> &mat){
        
        int m = mat.size() , n = mat[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)return -1;
        
        if((i!=x || j!=y) && (mat[x][y] >= mat[i][j]))return -1;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        // cout<<x<<" "<<y<<" -> "<<i<<" "<<j<<endl;
        
        int l = 1 + dfs(i,j-1,i,j,mat);
        int r = 1 + dfs(i,j+1,i,j,mat);
        int u = 1 + dfs(i-1,j,i,j,mat);
        int d = 1 + dfs(i+1,j,i,j,mat);
        
        return dp[i][j] = max({l,r,u,d});
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int m = mat.size() , n = mat[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = INT_MIN;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = dfs(i,j,i,j,mat);
                ans = max(ans,val);
            }
        }
        
        return 1 + ans;
    }
};