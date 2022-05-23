class Solution {
public:
    
    int memo[601][101][101];
    
    int find(int i,int x,int y,int m,int n,vector<vector<int>> &dp){
        
        int sz = dp.size();
        // cout<<i<<" "<<x<<" "<<y<<endl;
        if(x > m || y > n)return -1;

        if(i == sz)return 0;
            
        if(memo[i][x][y] != -1)return memo[i][x][y];
        
        int a = 1 + find(i+1,x+dp[i][0],y+dp[i][1],m,n,dp);
        int b = find(i+1,x,y,m,n,dp);
        
        return memo[i][x][y] = max(a,b);
    }
    
    int findMaxForm(vector<string>& str, int m, int n) {
        
        int sz = str.size();
        
        memset(memo,-1,sizeof(memo));
        
        vector<vector<int>> dp(sz);
        
        for(int i=0;i<sz;i++){
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