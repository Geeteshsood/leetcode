// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    
	    int n = s.size() , one = 0;
	    
	    for(int i=n-1;i>=0;i--){
	         
	         if(s[i] == '0')continue;
	         
	         int k = i-(n-1);
	         
	         if(k%2==0)one++;
	         else one--;
	         
	    }
	     
	     
	   // 2^k = (1-3)^k;
	    
	   //     = (3m + (-1)^k)%mod;
	   //     = (-1)^k;
	        
	  return (one)%3==0;  
	  
	}

};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends