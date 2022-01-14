class Solution {
public:
    
     unordered_set<string> se;
    
    bool find(int i,int j,string &s,vector<vector<int>> &dp){
        
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(se.count(s.substr(i,j-i+1)))return dp[i][j] = true;
        
        if(i == j)return dp[i][j] = false;
        
        for(int k=i;k<j;k++){
            bool f1 = find(i,k,s,dp);
            bool f2 = find(k+1,j,s,dp);
            
            if(f1 && f2)return dp[i][j] = true;
        }
        
        return dp[i][j] = false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto &it:wordDict){
            se.insert(it);
        }
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return find(0,n-1,s,dp);
    }
};