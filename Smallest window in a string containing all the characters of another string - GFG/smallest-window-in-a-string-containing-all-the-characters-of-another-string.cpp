// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    bool check(vector<int> &freq1 , vector<int> &freq2){
        
        for(int i=0;i<26;i++){
            if(freq1[i] > freq2[i]){
                return false;
            }
        }
        
       return true;
       
    }
    
    string smallestWindow (string s, string p)
    {
        
        int m = p.size() , n = s.size() , start = -1 , end = -1;
        
        vector<int> freq1(26) , freq2(26);
        
        for(int i=0;i<m;i++){
            freq1[p[i]-'a']++;
        }
    
        int i = 0 , j = 0 , mini = INT_MAX;
        
        while(i<=j && j<=n){
            
            if(check(freq1,freq2)){
                // cout<<j<<" "<<i<<endl;
                int len = j-i+1;
                if(len < mini){
                    mini = len;
                    start = i , end = j;
                }
                freq2[s[i]-'a']--;
                i++;
            }
            else{
                if(j!=n)freq2[s[j]-'a']++;
                j++;
            }
            
        }
        
        if(start == -1)return "-1";
        
        return s.substr(start,end-start);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends