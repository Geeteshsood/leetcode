class Solution {
public:
    
    bool isValid(int i,int j,int n){
        return !(i<0 || j<0 || i>=n || j>=n);
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<double>> cur(n,vector<double>(n));
        vector<vector<int>> dir {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
        
        cur[row][column] = (double)1;
        
     while(k>0){
        
        vector<vector<double>> next(n,vector<double>(n));
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                for(auto &it : dir){
                    int x = i + it[0] , y = j + it[1];
                    
                    if(isValid(x,y,n)){
                        next[x][y] += cur[i][j]/8;
                    }
                }
                
                
            }
        }
        k--;
        cur = next; 
     }  
        
     double sum = 0;
        
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             sum += cur[i][j];
         }
     }
        
      return sum;  
    }
};