class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        int r = mat.size() , c = mat[0].size();
    
        bool isCol = false;
        
        for(int i=0;i<r;i++){
            
            if(mat[i][0] == 0){
                isCol = true;
            }
            
            for(int j=1;j<c;j++){
                
                if(mat[i][j] == 0){
                  mat[i][0] = 0;
                  mat[0][j] = 0;
                }
            }
            
        }
        
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        for(int i=1;i<r;i++){

            for(int j=1;j<c;j++){
                if(mat[i][0] == 0|| mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }

        for(int j=0;j<c;j++){
            if(mat[0][0] == 0){
                mat[0][j] = 0;
            }
        }
        
        for(int i=0;i<r;i++){
            if(isCol){
                mat[i][0] = 0;
            }
        }
        
        
     
    }
};