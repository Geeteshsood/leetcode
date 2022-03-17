// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

#include<bits/stdc++.h>

class Solution{
    public:
    
      int gcd(int A, int B) 
	{ 
	    
	   if(B == 0)return A;
	   
	   return gcd(B,A%B);
	      
	} 
	
     vector<int> extGcd(int a, int b){
       
       if(b == 0){
          return {a,1,0};
       }
       
       vector<int> res = extGcd(b,a%b);
       
       int gcd1 = res[0] , x1 = res[1] , y1 = res[2];
       
       int x = y1;
       int y = x1 - (a/b)*y1;
       
       return {gcd1,x,y};
    }
    
    int modInverse(int a, int m)
    {
        if(gcd(a,m) != 1)return -1;
        
        vector<int> ans = extGcd(a,m);
        
        int val = (ans[1] + m)%m;
        
        return val == 0)?-1:val;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends