class Solution {
public:
    
    vector<vector<int>> find(vector<vector<int>> &grid){
        
         int m = grid.size() , n = grid[0].size();
         vector<vector<int>> sum(m+1,vector<int>(n+1));
        
         for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                sum[i][j] = grid[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i+1][j+1];
            }
        }

     return sum;
    }
    
    bool possibleToStamp(vector<vector<int>>& grid, int sh, int sw) {
        
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> sum = find(grid);    

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        // can we place a stamp or not.
        
        int val = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                int x = i+sh , y = j+sw;
                
                if(x > m || y > n)break;
                
                int topl = sum[i][j] , botr = sum[x][y] , botl = sum[x][j] , topr = sum[i][y];

                val = topl + botr - (topr + botl);
                
                if(val == 0){
                    dp[x-1][y-1] = 1;                   // if there is not a single occupied cell that means we can                                                                     place a stamp there.
                }
            }
        }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        // calculate prefix sum. of dp
        dp = find(dp);
      
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        // checking a particular point is covered by how many stamps.
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 1)continue;
                
                int x = min(m,i+sh) , y = min(n,j+sw);
                
                int topl = dp[i][j] , botr = dp[x][y] , botl = dp[x][j] , topr = dp[i][y];

                val = topl + botr - (topr + botl);
                
                if(val == 0){
                    return false;
                }
            }
        }
        
        return true;
    }
};