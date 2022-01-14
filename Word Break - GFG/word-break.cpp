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
    int wordBreak(string s, vector<string> &B) {
        
       unordered_set<string> dict;
        
        for(auto &i:B){
            dict.insert(i);
        }
        
        int n = s.size();
        vector<bool> dp(n);
        
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                string str = s.substr(i,j-i+1);
                if(dict.count(str) && (i == 0 || dp[i-1])){
                    dp[j] = true;
                    break;
                }
            }
        }
        
     return dp[n-1] ;  
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