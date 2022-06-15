// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    
    bool check(int i,int j,string &s){
        
        while(i <= j){
            if(s[i] == s[j]){
                i++,j--;
            }
            else return false;
        }
     
     return true;   
    }
    
    static bool cmp(string &s1 , string &s2){
        return s1.size()<s2.size();
    }
    
    bool palindromepair(int N, string arr[]) {
       
       sort(arr,arr+N,cmp);
       
       unordered_map<string,int> mp;
       
       for(int k=0;k<N;k++){
           
           int n = arr[k].size();
          
           for(int j=0;j<n;j++){
             if(check(0,j,arr[k])){
                 string str = arr[k].substr(j+1);
                 reverse(str.begin(),str.end());
                 if(mp.find(str) != mp.end()){
                      return true;
                 }
             }
           }
           
           for(int i=0;i<n;i++){
             if(check(i,n-1,arr[k])){
                 string str = arr[k].substr(0,i);
                 reverse(str.begin(),str.end());
                 if(mp.find(str) != mp.end()){
                      return true;
                 }
             }
           }
           
           string str = arr[k];
           reverse(str.begin(),str.end());
           
           if(mp.find(str) != mp.end())return true;
           
           mp[arr[k]] = k;
       }
        
        return false;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends