class Solution {
public:
    
    bool check(vector<bool> &per,vector<vector<int>> &mat){
    
        int n = mat.size();
        
        for(int i=0;i<n;i++){
            
            if(per[i] == 0)continue;
            
            for(int j=0;j<n;j++){
                if(mat[i][j] != 2 && mat[i][j] != per[j]){
                    return false;
                }
            }
        }
     
        return true;
    }
    
    int allPossible(int i,int cnt,int n,vector<bool> &per,vector<vector<int>> &mat){
        
        if(i == n){
            
           int ans = 0;
            
           if(check(per,mat)){
              ans = cnt;
           }
              
           return ans;
        }
        
        per[i] = true;
        int x = allPossible(i+1,cnt+1,n,per,mat);
        
        per[i] = false;
        int y = allPossible(i+1,cnt,n,per,mat);
        
        return max(x,y);
    }
    
    int maximumGood(vector<vector<int>>& mat) {
        
        int n = mat.size();

        vector<bool> per(n,false);
        
        return allPossible(0,0,n,per,mat);
    }
};