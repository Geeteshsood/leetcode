class Solution {
public:
    
    int find(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        
         if(dp[i][j] != -1)return dp[i][j];
        
         if(i == s.size() || j == t.size()){
             
             int cost = 0;
             
             for(int k=i;k<s.size();k++){
                 cost += (int)s[k];
             }
             for(int k=j;k<t.size();k++){
                 cost += (int)t[k];
             }
             
           return dp[i][j] = cost;
         }
         
         if(s[i] == t[j]){
             return dp[i][j] = find(i+1,j+1,s,t,dp);
         }
            
         int x = (int)s[i] + find(i+1,j,s,t,dp);
         int y = (int)t[j] + find(i,j+1,s,t,dp);
        
         return dp[i][j] = min(x,y);
    }
    
    int minimumDeleteSum(string s, string t) {
        
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return find(0,0,s,t,dp);
    }
};