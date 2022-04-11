class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size() , n = grid[0].size();
        k = k%(m*n);
        
        if(k == 0)return grid;
        
        vector<vector<int>> mat(m,vector<int> (n));
        
        int i = m-1 , j = n-1;
        int r = m-(k/n)-1;
        int c = n - k%n-1;
        
        while(true){
            
            if(j < 0)j = n-1,i--;
            if(c < 0){
                c = n-1;
                if(r == 0)break;
                else r--;
            }
            
            mat[i][j] = grid[r][c];
            
            c--;
            j--;
            
        }
        
        // cout<<i<<" "<<j<<endl;
        
        for(int r=m-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                mat[i][j] = grid[r][c];
                j--;
                if(j < 0){
                    j = n-1;
                    if(i == 0)return mat;
                    else i--;
                }
            }
        }
        
        return mat;
    }
};