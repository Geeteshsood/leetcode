class Solution {
public:
    
    int memo[601][101][101];
    
    int find(int i,int zero,int one,int m,int n,vector<vector<int>> &dp){
        
        int size = dp.size();
        
        if(zero > m || one > n)return -1;

        if(i == size)return 0;
            
        if(memo[i][zero][one] != -1)return memo[i][zero][one];
        
        int consider = 1 + find(i+1,zero+dp[i][0],one+dp[i][1],m,n,dp);
        int skip = find(i+1,zero,one,m,n,dp);
        
        return memo[i][zero][one] = max(consider,skip);
    }
    
    int findMaxForm(vector<string>& str, int m, int n) {
        
        int size = str.size();
        
        memset(memo,-1,sizeof(memo));
        
        vector<vector<int>> dp(size);
        
        for(int i=0;i<size;i++){
            int zero = 0 , one = 0;
            for(int j=0;j<str[i].size();j++){
                if(str[i][j] == '0')zero++;
                else one++;
            }
            dp[i].push_back(zero);
            dp[i].push_back(one);
        }
        
        return find(0,0,0,m,n,dp);
    }
};