class Solution {
public:
    
    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int findPaths(int m, int n, int maxMove, int sr, int sc) {

           int mod = 1e9 + 7;
           if(maxMove == 0)return 0;
        
           vector<int> dx{1,-1,0,0};
           vector<int> dy{0,0,1,-1};
        
           vector<vector<int>> prev(m,vector<int>(n)) , freq(m,vector<int>(n));
        
           queue<pair<int,int>> q;
        
           freq[sr][sc]++;
           prev[sr][sc]++;
        
           q.push({sr,sc});
        
            for(int p=1;p<maxMove;p++){
               
               vector<vector<int>> cur(m,vector<int>(n));
               vector<vector<bool>> vis(m,vector<bool>(n,false)); 
                
               int size = q.size();
                
               for(int x=0;x<size;x++){
                   
                   auto [i,j] = q.front();
                   q.pop();
                   
                   for(int k=0;k<4;k++){
                       
                      int x = i + dx[k];
                      int y = j + dy[k];
                       
                      if(isValid(x,y,m,n)){
                           if(!vis[x][y]){
                               q.push({x,y});
                               vis[x][y] = true;
                           }
                           cur[x][y] = (cur[x][y] + prev[i][j])%mod;
                      } 

                    }
                }
                
                prev = cur;
                
                for(int i=0;i<m;i++){
                   for(int j=0;j<n;j++){
                        freq[i][j] = (freq[i][j] + prev[i][j])%mod;
                   }
                }
            }
                
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 // cout<<freq[i][j]<<endl;
                 int cnt = 0;
                 for(int k=0;k<4;k++){
                       
                      int x = i + dx[k];
                      int y = j + dy[k];
                       
                      if(!isValid(x,y,m,n)){
                         cnt++;
                      } 

                }
                ans = (ans + (cnt * freq[i][j])%mod)%mod;
                
            }
        }
        
        return ans;
    }
};