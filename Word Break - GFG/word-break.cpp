// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

      class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        
        // unordered_set test case passed but 
        // unordered_map is giving TLE
        
         int n=A.size();
         int m1=B.size();
         
          unordered_set<string> dict;
          
          for(int i=0;i<m1;i++){
              dict.insert(B[i]);
          }
          
          vector<int>dp(n+1,0);
          dp[n]=1;
          
          for(int k=n-1;k>=0;k--){
              string s="";
              for(int i=k;i<n;i++){
                  s+=A[i];
                  if(dict.count(s) && dp[i+1]){
                      dp[k]=1;
                      break;
                  }
              }
          }
          return dp[0];
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends