class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        int r = mat.size() , c = mat[0].size();
    
        vector<int> row(r,-1) , col(c,-1);
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(row[i] == 0 || col[j] == 0){
                   mat[i][j] = 0;
               } 
            }
        }
        
        
    }
};