class Solution {
public:
    
    int mod = 1000000007; 
    
    vector<vector<int>> nxt = {{1} , {0 , 2} , {0 , 1 , 3 , 4} , {2 ,4} , {0}};
    
    int solve(int n , int c , int sz,vector<vector<int>> &dp){
        
        if(n == sz){
            return 1;
            
        }
        if(dp[sz][c] != -1) return dp[sz][c];
        
        int ans = 0;
        
        for(int i = 0 ; i<nxt[c].size() ; i++){
            
            ans = (ans + solve(n , nxt[c][i] , sz+1,dp))%mod;
            
        }
        return dp[sz][c] = ans;
        
    }
    
    int countVowelPermutation(int n) {
        
        vector<vector<int>> dp(n,vector<int>(5,-1));
        
        int ans = 0;
        for(int i = 0 ; i<5 ; i++){
            ans = (ans + solve(n , i , 1,dp))%mod;
        }
        return ans;
        
    }
};