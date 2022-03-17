// { Driver Code Starts



#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends

class Solution{
public:

    vector<int> gcd(int a, int b){
       
       if(b == 0){
          return {a,1,0};
       }
       
       vector<int> res = gcd(b,a%b);
       
       int gcd1 = res[0] , x1 = res[1] , y1 = res[2];
       
       int x = y1;
       int y = x1 - (a/b)*y1;
       
       return {gcd1,x,y};
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        vector<int> v = ob.gcd(a,b);
        if(v.size()!=3)
            return 0;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    return 0; 
}  // } Driver Code Ends