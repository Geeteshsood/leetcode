class Solution {
public:
    
    int lcs(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        
        int m = s.length() , n = t.length();
        
        if(j == n){
            return 1;
        }
        else if(i == m)return INT_MIN;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int val = 0;
        
        if(s[i] == t[j]){
            
            int x = lcs(i+1,j+1,s,t,dp);
            
            if(x != INT_MIN)val += x;
        }
        
        int y = lcs(i+1,j,s,t,dp);
        
        if(y != INT_MIN)val += y;
        
      return dp[i][j] = val;  
    }
    
    int numDistinct(string s, string t) {
        
       int m = s.length() , n = t.length();
       vector<vector<int>> dp(m,vector<int>(n,-1));
        
       return lcs(0,0,s,t,dp);
    }
};