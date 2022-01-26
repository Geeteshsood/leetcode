class Solution {
public:
    
    bool find(int i,vector<int> &arr,vector<bool> &vis){
        
        if(i < 0 || i >= arr.size() || vis[i])return false;
        
        vis[i] = true;
        
        if(arr[i] == 0)return true;
        
        return find(i + arr[i],arr,vis) || find(i - arr[i],arr,vis);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<bool> vis(n);
        
        return find(start,arr,vis);
    }
};