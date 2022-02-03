// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    typedef pair<int,pair<int,int>> pi;
    
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        
         sort(nums.begin(),nums.end());

             set<pi> s;
        
             vector<vector<int>> ans;
        
             int n = nums.size();
        
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    
                    int x = j+1 , y = n-1;
                    
                    while(x < y){
                        
                       int left = nums[i] + nums[j];
                       int right = nums[x] + nums[y];
                       
                       if(left == target - right){
                           if(!s.count({nums[i],{nums[j],nums[x]}})){
                               ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                               s.insert({nums[i],{nums[j],nums[x]}});
                           }
                           x++;
                       }
                       else if(left < target - right)x++;
                       else y--;
                    
                    } 
                }
            }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends