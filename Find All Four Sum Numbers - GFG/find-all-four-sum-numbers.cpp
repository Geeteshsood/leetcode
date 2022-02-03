// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        
            sort(nums.begin(),nums.end());

             vector<vector<int>> ans;
        
            int n = nums.size();
        
            for(int i=0;i<n;i++){
                
                while(i>0 && i<n && nums[i] == nums[i-1])i++;  
                
                for(int j=i+1;j<n;j++){
                    
                    while(j > i+1 && j<n && nums[j] == nums[j-1])j++;
                    
                    int x = j+1 , y = n-1;
                    
                    while(x < y){
                        
                       int  left = nums[i] + nums[j];
                       int right = nums[x] + nums[y];
                       
                       if(left == target - right){
                           ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                       }
                        
                       if(left <= target - right){
                           while( x<y && nums[x] == nums[x+1])x++;
                           x++;
                       }
                       else{
                           while( x<y && nums[y] == nums[y-1])y--;;
                           y--;
                       }
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