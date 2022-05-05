class Solution {
public:
    typedef pair<int,int> pi;
    
    bool isValid(int i,int j,int m,int n){
        
        return !(i < 0 || j < 0 || i >= m || j >= n);
        
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
       
        vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
        
        int m = grid.size() , n = grid[0].size();
        
        vector<vector<int>> fire(m,vector<int>(n,INT_MAX));
        
        queue<pi> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    fire[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int lev = 1;
        
        while(q.size()){
            
            int size = q.size();
            
            for(int k=0;k<size;k++){
                
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(auto &it : dir){
                    
                    int x = i + it[0];
                    int y = j + it[1];
                    
                    if(isValid(x,y,m,n) && grid[x][y] != 2 && fire[x][y] == INT_MAX){
                        fire[x][y] = lev;
                        q.push({x,y});
                    }
                }
            }
            lev++;
        }
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cout<<fire[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        int ans = -1;
        
        int maxi = 2 * 1e4 + 1;
        
        int start = 0 , end = maxi;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            vector<vector<int>> vis(m,vector<int>(n,false));
            
            lev = 1;
        
            q.push({0,0});
            
            while(q.size()){
                
                int size = q.size();
                
                for(int k=0;k<size;k++){
                    
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    
                    for(auto &it : dir){
                        
                        int x = i + it[0];
                        int y = j + it[1];
                        
                        if(x == m-1 && y == n-1 && mid + lev <= fire[x][y])vis[x][y] = true;
                        
                        if(isValid(x,y,m,n) && grid[x][y] != 2 && !vis[x][y] && mid + lev < fire[x][y]){
                            vis[x][y] = true;
                            q.push({x,y});
                        }
                    }
                }
                    
                lev++;
            }
                            
            if(vis[m-1][n-1])ans = mid,start = mid + 1;
            else end = mid-1;
        }
       
        if(ans == maxi)return 1e9;
        
        return ans;
    }
};