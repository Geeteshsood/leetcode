class Solution {
public:
    
    unordered_set<string> se;
    
    bool find(int i,int j,string &s,vector<int> &dp){
        
         if(dp[i] != -1)return dp[i];
        
         if(se.count(s.substr(i,j-i+1)))return dp[i] = true;
        
         if(i == j)return dp[i] = false;
        
        for(int k=i;k<j;k++){
            
            string str = s.substr(i,k-i+1);
            if(se.count(str)){
                if(find(k+1,j,s,dp)){
                    return dp[i] = true;
                }
            }
            
        }
        
      return dp[i] = false;  
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto &i:wordDict){
            se.insert(i);
        }
        
        int n = s.size();
        vector<int> dp(n,-1);
        
        return find(0,n-1,s,dp);
    }
};