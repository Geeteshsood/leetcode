class Solution {
public:
    
    int ans = INT_MIN;
    
    bool check(vector<bool> &per,vector<vector<int>> &mat){
    
        int n = mat.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(per[i] == 1 && mat[i][j]!=2){
                    if(mat[i][j] != per[j]){
                        return false;
                    }
                }
            }
        }
     
        return true;
    }
    
    void allPossible(int i,int cnt,int n,vector<bool> &per,vector<vector<int>> &mat){
        
        if(i == n){
            
          bool flag = check(per,mat);
        
         if(flag)ans = max(ans,cnt);
            
         return ;
        }
        
        per[i] = true;
        allPossible(i+1,cnt+1,n,per,mat);
        
        per[i] = false;
        allPossible(i+1,cnt,n,per,mat);
    }
    
    int maximumGood(vector<vector<int>>& mat) {
        
        int n = mat.size();

        vector<bool> per(n,false);
        allPossible(0,0,n,per,mat);

        return ans;
    }
};