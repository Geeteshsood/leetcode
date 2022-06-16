class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int n = s.size() , len = 0 , maxi = INT_MIN , st = -1;
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    
                   if(s[i] == s[j] && dp[i+1][j-1]){
                       dp[i][j] = true;
                   }
                    
                }
                
                if(dp[i][j]){
                    int len = j-i+1;
                    if(len > maxi){
                        st = i;
                        maxi = len;
                    }
                }
            }
        }
        
       return s.substr(st,maxi);
    }
};