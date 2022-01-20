class Solution {
public:
    
    int find(int i,int j,vector<vector<int>> &dp,string &s){
        
        if(i >= j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int val = 0;
        
        if(s[i] == s[j]){
            val = find(i+1,j-1,dp,s);
        }
        else{
            val = 1 + min(find(i+1,j,dp,s),find(i,j-1,dp,s));
        }
        
      return dp[i][j] = val;  
    }
    
    int minInsertions(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return find(0,n-1,dp,s);
        
    }
};