class Solution {
public:
    
    int find(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        
        if(i == s.size() || j == t.size()){
            return t.size() + s.size() - i - j;
        }
 
        if(dp[i][j] != -1)return dp[i][j];
        
        int val = INT_MAX;
        
        if(s[i] == t[j]){
            val = find(i+1,j+1,s,t,dp);
        }
        else{
            
            int x = 1 + find(i,j+1,s,t,dp);        // insert  
            int y = 1 + find(i+1,j,s,t,dp);        // delete
            int z = 1 + find(i+1,j+1,s,t,dp);      // replace
            
            val = min({val,x,y,z});
        }
        
        return dp[i][j] = val;
    }
    
    int minDistance(string s, string t) {
        
          int m = s.size() , n = t.size();
          vector<vector<int>> dp(m,vector<int>(n,-1));
        
          return find(0,0,s,t,dp);
    }
};