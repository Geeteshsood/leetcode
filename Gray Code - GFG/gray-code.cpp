// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    bool find(string s,int cnt,int one,vector<string> &ans,unordered_map<string,bool> &vis){
        
        // cout<<s<<" "<<one<<endl;
        int n = s.size();
        if(cnt == (1<<n)){
            
            if(one == 1){
                return true;
            }
            
            return false;
        }
        
        vis[s] = true;
        
        for(int i=n-1;i>=0;i--){
            // cout<<s<<endl;
            if(s[i] == '1')s[i] = '0',one--;
            else s[i] = '1',one++;

            if(!vis[s] && find(s,cnt+1,one,ans,vis)){
                
                ans.push_back(s);
                return true;
            }
            
            if(s[i] == '1')s[i] = '0',one--;
            else s[i] = '1',one++;
        }
        
        vis[s] = false;
        
        return false;
    }
    
    vector<string> graycode(int n)
    {
         vector<string> ans;
         unordered_map<string,bool> vis;
         
         string s;
        
         for(int i=0;i<n;i++){
             s += '0';
         }
        
         find(s,1,0,ans,vis);
         ans.push_back(s);
        
         reverse(ans.begin(),ans.end());
        
        return ans;
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
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends