class Solution{
public:
    typedef pair<int,int> pi;
    
    int col = -1;
    
    bool isValid(int i,int j,int m,int n){
        
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int dfs(vector<vector<int>> &grid,int i,int j){
        
        int m = grid.size() , n = grid[0].size();
        
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= 0)return 0;
        
        grid[i][j] = col;
        
        int x = 0;
        
        x += dfs(grid,i+1,j);
        x += dfs(grid,i-1,j);
        x += dfs(grid,i,j+1);
        x += dfs(grid,i,j-1);

        return 1 + x;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                     int size = dfs(grid,i,j);
                     mp[col] = size;
                     col--;
                }
            }
        }
        
        bool flag = true;
        int ans= 0;
        
        vector<pi> dir{{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    flag = false;
                    unordered_set<int> s;
                    int val = 0;
                    for(auto &it : dir){
                        
                        int x = i + it.first;
                        int y = j + it.second;
                        
                        if(isValid(x,y,m,n) && !s.count(grid[x][y])){
                            s.insert(grid[x][y]);
                            val += mp[grid[x][y]];
                        }
                    }
                    ans = max(ans,val);
                }
            }
        }  
        
        if(flag)return m*n;
        
        return 1 + ans;
    }
};