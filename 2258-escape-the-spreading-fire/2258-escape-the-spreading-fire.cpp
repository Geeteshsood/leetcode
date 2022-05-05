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
        
        queue<pi> qu;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    fire[i][j] = 0;
                    qu.push({i,j});
                }
            }
        }
        
        int lev = 1;
        
        while(qu.size()){
            
            int size = qu.size();
            
            for(int k=0;k<size;k++){
                
                int i = qu.front().first;
                int j = qu.front().second;
                qu.pop();
                
                for(auto &it : dir){
                    
                    int x = i + it[0];
                    int y = j + it[1];
                    
                    if(isValid(x,y,m,n) && grid[x][y] != 2 && fire[x][y] == INT_MAX){
                        fire[x][y] = lev;
                        qu.push({x,y});
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

            vector<vector<int>> vis(m,vector<int>(n,false));
            
            lev = 1;
        
            queue<pair<pair<int,int>,int>> q;
            q.push({{0,0},INT_MAX});
            
            while(q.size()){
                
                int size = q.size();
                
                for(int k=0;k<size;k++){
                    
                    int i = q.front().first.first;
                    int j = q.front().first.second;
                    int val = q.front().second;
                    
                    q.pop();
                    
                    for(auto &it : dir){
                        
                        int x = i + it[0];
                        int y = j + it[1];
                        
                        if(x == m-1 && y == n-1 && lev <= fire[x][y]){
                            int res = INT_MAX;
                            if(fire[x][y] != INT_MAX){res = min(val , fire[x][y]-lev);
                            ans = max(ans,res);}
                            vis[x][y] = true;
                        }
                        else if(isValid(x,y,m,n) && grid[x][y] != 2 && !vis[x][y] && lev < fire[x][y]){
                            vis[x][y] = true;
                            int res = INT_MAX;
                            if(fire[x][y] != INT_MAX)res = min(val , fire[x][y]-lev-1);
                            q.push({{x,y},res});
                        }
                    }
                }
                    
                lev++;
            }
                            
            if(!vis[m-1][n-1])return -1;
       
            if(ans == -1)return 1e9;
        
        return ans;
    }
};