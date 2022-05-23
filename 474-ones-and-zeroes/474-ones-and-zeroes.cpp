class Solution {
public:
    
    void count(string &s,int &zero,int &one){
        
        for(auto &i : s){
            if(i == '0')zero++;
            else one++;
        }
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(auto &str : strs){
            
            int zero = 0 , one = 0;
            
            count(str,zero,one); 
            
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=one;j--){
                    dp[i][j] = max(1 + dp[i-zero][j-one] , dp[i][j]);
                }
            }
            
        }
       
     return dp[m][n];
    }
};