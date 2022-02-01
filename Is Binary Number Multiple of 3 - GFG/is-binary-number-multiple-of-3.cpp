// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    
	    int n = s.size() , sum = 0 , prev = 1 , cur = 0;
	    
	    if(s[n-1] == '1')sum = 1;

	    for(int bit=n-2;bit>=0;bit--){
	        
	        cur = (2*prev)%3;

	        if(s[bit] == '1')sum += cur;
	        
	        prev = cur;
	    }
	  
	   //  2^29 = 2 * 2^28;
	     
	   //  (2^29)%mod = ((2)%mod * (2^28)%mod)%mod;
	     
	   //  2^28 we have calculated earlier it must be of 0 , 1 or 2
	   //  in this way our ans will be never be out of range.
	     
	     
	  return sum%3==0;  
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