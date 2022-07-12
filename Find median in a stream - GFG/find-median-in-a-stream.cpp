// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    
     priority_queue<int> maxi;
     priority_queue<int,vector<int>,greater<int>> mini;

    //Function to insert heap.
    void insertHeap(int &num)
    {
         int m = maxi.size() , n = mini.size();
        
       if(m == n){
           if(n > 0 && num > mini.top()){
               maxi.push(mini.top());
               mini.pop();
               mini.push(num);
           }
           else maxi.push(num);
       }
       else{
           if(num < maxi.top()){
               int val = maxi.top();
               maxi.pop();
               maxi.push(num);
               mini.push(val);
           }
           else mini.push(num);
       }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int n = maxi.size() + mini.size();
        
        if(n%2 != 0){
            return maxi.top();
        }
       
        return (double)(maxi.top() + mini.top())/(double)2;
        
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends