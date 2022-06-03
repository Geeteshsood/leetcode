class NumMatrix {
public:
    
    vector<vector<int>> mat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        mat = matrix;
        
        int m = mat.size() , n = mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0)continue;
                else if(i == 0)mat[i][j] += mat[i][j-1];
                else if(j == 0)mat[i][j] += mat[i-1][j];
                else mat[i][j] += mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
            }
        }
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
          // cout<<row1<<" "<<col1<<" -> "<<row2<<" "<<col2<<endl;
        
          int x = 0 , y = 0 , z = 0;
        
          if(row1 > 0 && col1 > 0)x = mat[row1-1][col1-1];
          if(row1 > 0)y = mat[row1-1][col2];
          if(col1 > 0)z = mat[row2][col1-1];
        
          // cout<<x<<" "<<y<<" "<<z<<endl;
          return mat[row2][col2] + x - (y + z);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(mat);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */