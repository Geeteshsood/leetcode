// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:

    bool dfs(int i,vector<bool> &vis,vector<vector<int>> &adj){
        
        vis[i] = true;
        
        for(auto &it : adj[i]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
        
    }
    
    int isCircle(int N, vector<string> A)
    {
    
       vector<bool> mark(26,false);
       
       vector<int> outdegree(26),indegree(26);
       
       vector<vector<int>> adj(26,vector<int>());

       for(int i=0;i<N;i++){
           
           int m = A[i].size();
           
           int u = A[i][0]-'a';
           int v = A[i][m-1]-'a';
           
           outdegree[v]++;
           indegree[u]++;
           
           adj[u].push_back(v);
           
           mark[u] = true , mark[v] = true;
       }
       
       for(int i=0;i<26;i++){
           if(outdegree[i] != indegree[i]){
               return false;
           }
       }

       vector<bool> vis(26,false);
       char ch = A[0][0];
       
       dfs(ch-'a',vis,adj);
       
       for(int i=0;i<26;i++){
           if(!vis[i] && mark[i]){
               return false;
           }
       }
       
       return true;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends