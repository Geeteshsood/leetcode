// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	typedef long long ll;
	
	long long getCount(int N)
	{
		
	vector<vector<int>> digit(10,vector<int>());
	
	digit[0] = {0,8} , digit[1] = {1,2,4} , digit[2] = {2,1,5,3}, digit[3] = {3,2,6} , digit[4] = {4,1,5,7},
	digit[5] = {5,2,4,8,6} , digit[6] = {6,3,5,9} , digit[7] = {7,4,8} , digit[8] = {8,5,7,9,0}, digit[9] = {9,6,8};
	
	vector<ll> prev(10,1);
	
    for(int k=2;k<N+1;k++){
      vector<ll> cur(10);
	  for(int i=0;i<10;i++){
	     for(auto &x:digit[i]){
	         cur[x] += prev[i];
	     }
	  }
      prev = cur;  
    }
    
    ll sum = 0;
    
    for(auto &x:prev){
        sum += x;
    }  
    
	return sum;
	
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends