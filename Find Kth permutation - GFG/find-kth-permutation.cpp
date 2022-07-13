// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    string dfs(string &str,int fact,int n,int k){
        
        if(n == 0)return "";
        
        int block = fact/n;
        
        int idx =((k-1)/block);
        
        k = k - (idx*block);
        
        char ch = str[idx];
        str.erase(idx,1);
        
        return ch + dfs(str,fact/n,n-1,k);
     
    }
    
    string kthPermutation(int n, int k)
    {
      string str;
        
       for(int i=1;i<=n;i++){
           str += to_string(i);
       }
        
        int fact = 1;
        for(int i=1;i<=n;i++){
            fact= fact*i;
        }
        
       return dfs(str,fact,n,k);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends