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
        
        int m = p.size() , n = s.size();
        
        vector<int> freq(26);
        
        int count = 0;
        
        for(int i=0;i<m;i++){
            if(freq[p[i]-'a'] == 0)count++;
            freq[p[i]-'a']++;
        }
    
        int i = 0 , j = 0 , mini = INT_MAX , start = -1 , end = -1;
        
        while(j < n){
            
            freq[s[j]-'a']--;
            
            if(freq[s[j]-'a'] == 0)count--;
            
            if(count == 0){
                
                while(i<=j && count == 0){
                    
                    int len = j - i + 1;
                    
                    if(len < mini){
                        mini = len;
                        start = i , end = j;
                    }
                    
                    freq[s[i]-'a']++;
                    
                    if(freq[s[i]-'a'] > 0)count++;
                    
                    i++;
                }
                
            }
            j++;
        }
        
        if(start == -1)return "-1";
        
        return s.substr(start,end-start+1);
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