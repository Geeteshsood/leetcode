// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	   
	    unordered_map<int,int> mp;
        
        for(auto &i:nums){
            mp[i]++;
        }

        int n = nums.size();
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
        
            if(mp[nums[i]] == -1)continue;
            
            int num1 = nums[i] + k;
            
            if(k == 0 && mp[num1] > 1)cnt++;
            else if(k != 0 && mp.count(num1))cnt++;
            
            mp[nums[i]] = -1;
        }
        
     return cnt;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends