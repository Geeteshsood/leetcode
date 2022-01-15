// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    
    int find(int i,int j,int nums[],bool flag,vector<vector<int>> &dp){
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == j){
            if(flag)return nums[i];
            else return -nums[i];
        }
        
        int val = 0;
        
        if(flag){ 
            int s1 = find(i+1,j,nums,false,dp);
            int s2 = find(i,j-1,nums,false,dp);
            
            s1 += nums[i] , s2 += nums[j];
            
            val = max(s1,s2);
        }
        else{
            
            int s1 = find(i+1,j,nums,true,dp);
            int s2 = find(i,j-1,nums,true,dp);
            
            s1 -= nums[i] , s2 -= nums[j];
            
            val = min(s1,s2);
        }
     
     return dp[i][j] = val ;
    }
    
    long long maximumAmount(int nums[], int n){
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int score = find(0,n-1,nums,true,dp);
        
        int sum = 0;
        for(int i=0;i<n;i++)sum += (int)nums[i];
        
      return (score + sum)/2; 
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends