class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size() , val = 0;
        vector<int> dp(n + 1);
        
        if(s[0] != '0')dp[0] = 1;
        
        for(int i=1;i<=n;i++){
            
             if(s[i-1] != '0')dp[i] = dp[i-1];
            
            if(i>=2 && s[i-2] != '0'){ 
                val = (s[i-1]-'0') + (s[i-2]-'0')*10;
            
                if(val >=1 && val <= 26){
                    dp[i] += dp[i-2];
                }
            }    
        }

        return dp[n];
    }
    
};