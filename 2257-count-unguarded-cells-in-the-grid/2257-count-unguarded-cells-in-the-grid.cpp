class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<char>> mat(m,vector<char>(n,'T'));
        
        for(auto &it: guards){
            mat[it[0]][it[1]] = 'G';
        }
        
        for(auto &it : walls){
            mat[it[0]][it[1]] = 'W';
        }
     
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(mat[i][j] != 'G')continue;
                    
                for(int k=j+1;k<n;k++){
                   if(mat[i][k] == 'W' || mat[i][k] == 'G')break;
                   else mat[i][k] = 'F';
                }
                for(int k=j-1;k>=0;k--){
                   if(mat[i][k] == 'W' || mat[i][k] == 'G')break;
                   else mat[i][k] = 'F';
                }
                for(int k=i+1;k<m;k++){
                   if(mat[k][j] == 'W' || mat[k][j] == 'G')break;
                   else mat[k][j] = 'F';
                }
                for(int k=i-1;k>=0;k--){
                   if(mat[k][j] == 'W' || mat[k][j] == 'G')break;
                   else mat[k][j] = 'F';
                }
            }
        }
        
        int ans = 0 ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<mat[i][j]<<" ";
                if(mat[i][j] == 'T'){
                    ans++;
                }
            }
            // cout<<endl;
        }
        
        return ans;
    }
};