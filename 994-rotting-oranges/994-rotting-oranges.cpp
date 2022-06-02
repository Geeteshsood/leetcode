class Solution {
public:
    typedef pair<int,int> pi;
    
    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        queue<pi> q;
        int total = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    total++;
                }
            }
        }
        
        if(total == 0)return 0;
        
        int time = 0;
        
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        
        while(q.size()){
            
            int size = q.size();
            
            for(int k=0;k<size;k++){
                
                int i = q.front().first , j = q.front().second;
                
                q.pop();
                
                for(auto &it : dir){
                    int x = i + it[0];
                    int y = j + it[1];
                    
                    if(isValid(x,y,m,n) && grid[x][y] == 1){
                        total--;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            
            time++;
        }
        
        if(total > 0)return -1;
        
       return time-1; 
    }
};