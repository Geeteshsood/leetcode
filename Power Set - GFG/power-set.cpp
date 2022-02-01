// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		   
		   int n = s.size();
		   vector<string> ans;
		   
		   for(int num=1;num<(1<<n);num++){
		       
		       string str;
		       
		       for(int bit=0;bit<n;bit++){
		           
		           if(num & (1<<bit)){
		                str += s[bit];
		           }
		       }
		       
		       ans.push_back(str);
		   }
		   
		   sort(ans.begin(),ans.end());
		   
		   return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends