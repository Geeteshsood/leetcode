// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	typedef long long ll;
	
	unordered_map<int,ll> find(int i,int N,unordered_map<int,vector<int>> &digit){
	    
	  if(i==N-1){
	      unordered_map<int,ll> v;
	      for(int i=0;i<10;i++)v[i] = (ll)1;
	      return v;
	  }
	  
	  auto cur = find(i+1,N,digit)  ;
	  unordered_map<int,ll> nex;
	  
	  for(auto &it:cur){
	     for(auto &x:digit[it.first]){
	         nex[x] += cur[it.first];
	     }
	  }
	    
	 return nex;   
	}
	
	
	long long getCount(int N)
	{
		
	unordered_map<int,vector<int>> digit;
	digit[0] = {0,8} , digit[1] = {1,2,4} , digit[2] = {2,1,5,3}, digit[3] = {3,2,6} , digit[4] = {4,1,5,7},
	digit[5] = {5,2,4,8,6} , digit[6] = {6,3,5,9} , digit[7] = {7,4,8} , digit[8] = {8,5,7,9,0}, digit[9] = {9,6,8};
	
	unordered_map<int,ll> freq = find(0,N,digit);
	
	ll sum = 0;
	for(auto &x:freq)sum+=x.second;
	
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