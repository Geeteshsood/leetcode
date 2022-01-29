// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	 int mod = 1e9 + 7;
	 
	 int find(int i,string &str,vector<int> &dp){
        
        if(i == str.size())return 1;
        
        int sum = 0;
        
        if(dp[i] != -1)return dp[i];
        
        for(int j=i;j<str.size();j++){
            
            int val = stoi(str.substr(i,j-i + 1));
            
            if(val < 1 || val > 26)break;
                
            sum = (sum + find(j + 1,str,dp))%mod;
        }
        
      return dp[i] = sum;  
    }
    
		int CountWays(string str){
		   
		   vector<int> dp(str.size(),-1);
		   
		   return find(0,str,dp);
		    
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends