// { Driver Code Starts
#include<iostream>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int isPowerOfFour(unsigned int n)
    {
      
       unsigned int rsb = n & -n;
       if(n != rsb)return 0;
       
       for(int i=0;i<32;i++){
            if(n & (1 << i)){
                if(i%2 != 0)return 0;
            }
       }
      
      return 1;
    }
};

// { Driver Code Starts.

/*Driver program to test above function*/
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
Solution ob;
if(ob.isPowerOfFour(n))
	cout<<1<<endl;
else
	cout<<0<<endl;
}
//getchar();
}
  // } Driver Code Ends