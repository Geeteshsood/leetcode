class Solution {
public:
    
    int find(int i,vector<vector<int>> &dp,vector<int> &vis){
        
        int m = dp.size();
        
        if(i == m)return 0;
        
        int val = 0;
        
        for(int j=0;j<m;j++){
            
            if(!vis[j]){
                vis[j] = true;
                val = max(val , dp[i][j] + find(i+1,dp,vis));
                vis[j] = false;
            }
            
        }
        
     return val;   
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int m = students.size() , n = students[0].size();
        
        vector<vector<int>> dp(m,vector<int>(m));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                
                int score = 0;
                
                for(int k=0;k<n;k++){
                    if(students[i][k] == mentors[j][k]){
                        score++;
                    }
                }
                
                dp[i][j] = score;
            }
        }
        
        vector<int> vis(m,false) ;
        
        return find(0,dp,vis);
    }
};