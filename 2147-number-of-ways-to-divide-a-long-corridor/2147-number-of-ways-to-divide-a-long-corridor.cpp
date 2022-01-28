class Solution {
public:
    int mod = 1e9 + 7;
    
    int find(int i,int cnt,string &s,vector<vector<int>> &dp){
        
        int n = s.size();
        
        if(s[i] == 'S')cnt++;
        if(cnt > 2)return 0;
        
        if(i == n-1){
            if(cnt == 2)return 1;
            
            return 0;
        }
        
        if(dp[i][cnt] != -1)return dp[i][cnt];
        
        int x = 0 , y = 0;
        
        if(cnt == 2){
           x =  find(i+1,0,s,dp);
        }
        
        y = find(i+1,cnt,s,dp);
        
     return dp[i][cnt] = (x + y)%mod;   
    }
    
    int numberOfWays(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        
        return find(0,0,s,dp);
        
    }
};