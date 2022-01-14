class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> se;
        
        for(auto &i:wordDict){
            se.insert(i);
        }
        
        int n = s.size();
        vector<bool> dp(n);
        
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                string str = s.substr(i,j-i+1);
                if(se.count(str) && (i == 0 || dp[i-1])){
                    dp[j] = true;
                    break;
                }
            }
        }
        
     return dp[n-1] ;  
    }
};