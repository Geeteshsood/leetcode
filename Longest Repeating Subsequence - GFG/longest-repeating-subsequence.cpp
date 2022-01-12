// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	
	int lcs(int i,int j,string &s,vector<vector<int>> &dp){
	    
	    if(i==s.size() || j==s.size())return 0;
	    
	    if(dp[i][j] != -1)return dp[i][j];
	    
	    if(s[i] == s[j] && i!=j){
	        return dp[i][j] = 1 + lcs(i+1,j+1,s,dp);
	    }

	   return dp[i][j] = max( lcs(i,j+1,s,dp) , lcs(i+1,j,s,dp));
	}
	
	int LongestRepeatingSubsequence(string s){
	    
	    int n = s.size();
	    vector<vector<int>> dp(n,vector<int>(n,-1));
	    
        return lcs(0,0,s,dp);	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends