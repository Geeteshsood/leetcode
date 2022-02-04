class Solution {
public:
    
    vector<vector<int>> find(vector<vector<int>> &grid){
        
         int m = grid.size() , n = grid[0].size();
         vector<vector<int>> sum(grid);
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                if(i > 0 && j > 0 )sum[i][j] -= sum[i-1][j-1];
                if(j > 0 )sum[i][j] += sum[i][j-1];
                if(i > 0)sum[i][j] += sum[i-1][j];
            }
        }

     return sum;
    }
    
    bool possibleToStamp(vector<vector<int>>& grid, int sh, int sw) {
        
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> sum = find(grid);    
//            for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cout<<sum[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        vector<vector<int>> dp(m,vector<int>(n));
        
        // can we place a stamp or not.
        
        int val = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                int x = i-sh , y = j-sw;
            
                if(x < 0 && y < 0){
                    val = sum[i][j];
                }
                else if( y < 0){
                    val = sum[i][j] - sum[x][j];
                }
                else if( x < 0){
                    val = sum[i][j] - sum[i][y];
                }
                else{
                    
                  val = sum[i][j] + sum[x][y] - (sum[x][j] + sum[i][y]);
                }
                  if(val == 0 && x+1>=0 && y+1>=0){
                      dp[x+1][y+1] = 1;
                  }
                 // cout<<i<<" "<<j<<" "<<val<<endl;
            }
        }
        // cout<<" *** "<<endl;
        
        // calculate prefix sum. of dp
        vector<vector<int>> res = find(dp);
        
        //    for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<res[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // checking a particular point cover by how many stamps.
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)continue;
                int x = i-sh , y = j-sw;
                
                if(x < 0 && y < 0){
                    val = res[i][j];
                }
                else if( y < 0){
                    val = res[i][j] - res[x][j];
                }
                else if( x < 0){
                    val = res[i][j] - res[i][y];
                }
                else val = res[i][j] + res[x][y] - (res[x][j] + res[i][y]);
                
                if(val == 0){
                    return false;
                }
            }
        }

        return true;
    }
};