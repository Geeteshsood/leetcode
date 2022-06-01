// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done
    
    static bool cmp(Job &x,Job &y){
    
        if(x.profit == y.profit){
           return x.dead >= y.dead;
        }
    
        return x.profit > y.profit;

    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> vis(n+1,-1);
        
        sort(arr,arr+n,cmp);
        
        for(int i=0;i<n;i++){
            
            int tm = min(n,arr[i].dead);
            
            while(vis[tm] != -1 && tm > 0){
                tm--;
            }
            
            if(tm > 0)vis[tm] = arr[i].profit;
            
        }
   
        int cnt = 0 , pro = 0;
        
        for(int i=0;i<=n;i++){
            if(vis[i] > 0){
                cnt++;
                pro += vis[i];
            }
        }
        
        return {cnt,pro};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends