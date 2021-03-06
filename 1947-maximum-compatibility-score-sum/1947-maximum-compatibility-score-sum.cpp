class Solution {
public:
    
    int mem[8][1<<8];
    
    int find(int i,vector<vector<int>> &dp,int mask){
        
        int m = dp.size();
        
        if(i == m)return 0;
        
        if(mem[i][mask] != -1){
            return mem[i][mask];
        }
        
        int val = 0;
        
        for(int j=0;j<m;j++){
            
            if(!(mask & (1<<j))){
                mask = mask | (1<<j);
                val = max(val , dp[i][j] + find(i+1,dp,mask));
                mask = mask ^ (1<<j);
            }
            
        }
        
     return mem[i][mask] = val;   
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
        
        memset(mem,-1,sizeof(mem));
        
        int mask = 0;
        
        return find(0,dp,mask);
    }
};