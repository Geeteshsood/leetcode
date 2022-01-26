class Solution {
public:
    
    bool find(int i,vector<int> &arr,vector<bool> &vis,vector<int> &dp){
        
        if(i < 0 || i >= arr.size() || vis[i])return false;
        
        vis[i] = true;
        
        if(dp[i] != -1)return dp[i];
        
        if(arr[i] == 0)return true;
        
        return dp[i] = find(i + arr[i],arr,vis,dp) || find(i - arr[i],arr,vis,dp);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<bool> vis(n);
        vector<int> dp(n,-1);
        
        return find(start,arr,vis,dp);
    }
};