class Solution {
public:
     
    vector<vector<string>> ans;     
    
     void print(vector<vector<int>> &mat){
             
         int n = mat.size();
         
         vector<string> v;    
         for(int i=0;i<n;i++){
             string str;    
             for(int j=0;j<n;j++){
                 if(mat[i][j]==-2)str+='Q';
                 else str+='.';
             } 
            v.push_back(str);     
         }    
           ans.push_back(v);
     } 

    
    // blocking path for queen
    void block(vector<vector<int>> &mat,int i,int j,int col,int recol){
        
           int n = mat.size();
        
           for(int k=i+1;k<n;k++){
               if(mat[k][j]==col){
                   mat[k][j] = recol;
               }
           }
        
           for(int x=i+1,y=j+1;x<n && y<n;x++,y++){
               if(mat[x][y]==col){
                   mat[x][y] = recol;
               }
           }
        
           for(int x=i+1,y=j-1;x<n && y>=0;x++,y--){
                if(mat[x][y]==col){
                    mat[x][y] = recol;
                }
           }
    }
    
    // for finding safe position for queen.
    void queen(vector<vector<int>> &mat,int i,int j){
        
        int n = mat.size();
        
        if(i == n){
            print(mat);
            return;
        }
        
        if(j==n){
            return ;
        }
    
        if(mat[i][j] == -1){
            block(mat,i,j,-1,i);      // j col change to i col (block)
            mat[i][j] = -2;
            
            queen(mat,i+1,0);
            
            block(mat,i,j,i,-1);      // i col change to j col  (unblock)
            mat[i][j] = -1;
        }
        
        queen(mat,i,j+1);
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>> mat (n,vector<int>(n,-1));
        
        int i=0;
        for(int j=0;j<n;j++){
            
            block(mat,i,j,-1,i);
            mat[i][j] = -2;
            
            queen(mat,i+1,0);
            
            block(mat,i,j,i,-1); 
            mat[i][j] = -1;
        } 
        
    return ans;
    }
};