class Solution {
public:
    
    bool find(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        
        int x = s1.size() , y = s2.size() , z = s3.size();
        
        if(i == x && j == y && k == z)return true;
        
        if(i<x && j<y && dp[i][j] != -1)return dp[i][j];
        
        bool flag = false;
        
        if(i<x && j<y && k<z &&  s1[i] == s3[k] && s2[j] == s3[k]){
             flag = find(i+1,j,k+1,s1,s2,s3,dp) || find(i,j+1,k+1,s1,s2,s3,dp);
        }
        else if(i<x && k<z &&s1[i] == s3[k]){
             flag = find(i+1,j,k+1,s1,s2,s3,dp);
        }
        else if(j<y && k<z && s2[j] == s3[k]){
             flag = find(i,j+1,k+1,s1,s2,s3,dp);
        }
        
       if(i<x && j<y)dp[i][j] = flag; 
        
       return flag;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        
        return find(0,0,0,s1,s2,s3,dp);
    }
};