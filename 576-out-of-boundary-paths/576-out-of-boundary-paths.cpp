class Solution {
public:
    
    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        int mod = 1e9 + 7;
        vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}}; 
        
        int cnt = 0;
        vector<vector<int>> temp(m,vector<int>(n));
        temp[startRow][startColumn] = 1;
        
        for(int moves=0;moves<maxMove;moves++){
            
            vector<vector<int>> dp(m,vector<int>(n)); 
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    
                    if(i == 0)cnt = (cnt + temp[i][j])%mod;
                    if(j == 0)cnt = (cnt + temp[i][j])%mod;
                    if(i == m-1)cnt = (cnt + temp[i][j])%mod;
                    if(j == n-1)cnt = (cnt + temp[i][j])%mod;
                        
                    for(auto &it : dir){
                        
                        int x  = i + it[0];
                        int y  = j + it[1];
                        
                        if(isValid(x,y,m,n)){
                            dp[x][y] = (dp[x][y] + temp[i][j])%mod;
                        }
                        
                    }
                    
                }
            }
            
            temp = dp;
        }
        
        return cnt;
    }
};