// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  
    void find(int i,int sum,int nums[],int n,int mask,unordered_map<int,vector<int>> &mp){
      
        if(i == n){
            mp[sum].push_back(mask);
            return ;
        }
        
        find(i+1,sum + nums[i],nums,n,mask|(1<<i),mp);
        find(i+1,sum,nums,n,mask,mp);
    }
    
    bool check(int i,int mask,int cnt,vector<int> &res,int k,int &target){
        
        int n = res.size();
        
        if(cnt == k){
            return mask == target;
        }
        if(i == n || cnt > k)return false;
            
        bool flag = false;
        
        if(!(mask & res[i])){
            flag = check(i+1,mask^res[i],cnt+1,res,k,target);
        }
        return flag || check(i+1,mask,cnt,res,k,target);
    }
    
    bool isKPartitionPossible(int nums[], int n, int k)
    {
            
        unordered_map<int,vector<int>> mp;  
        find(0,0,nums,n,0,mp);
        
        int target = 0;
        target = 1<<n;
        target-=1;
        
        for(auto it:mp){
            vector<int> res = it.second;
            if(res.size() >= k){
                if(check(0,0,0,res,k,target)){
                    return true;
                }
            }
        }
        
       return false; 
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends