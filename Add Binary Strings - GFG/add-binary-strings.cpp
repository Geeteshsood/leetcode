// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    string str;
        int carry = 0 , sum = 0;
        int i = a.size()-1 , j = b.size()-1;
        
        int s1 = 0 , s2 = 0;
        for(s1=0;s1<=i;s1++){
            if(a[s1] == '1')break;
        }
        
        for(s2=0;s2<=i;s2++){
            if(b[s2] == '1')break;
        }
        
        while(i >=s1 || j >=s2 || carry){
            
             int x = 0 , y = 0;
        
             if(i >= s1){
                 x = a[i]-'0';
                 i--;
             }
            
             if(j >= s2){
                 y = b[j]-'0';
                 j--;
             }
            
             sum = x^y^carry;
            
             str += sum + '0';
             
             carry = (x | y) && (x | carry) && (y | carry);
        }
        
        reverse(str.begin(),str.end());
        
      return str;  
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends