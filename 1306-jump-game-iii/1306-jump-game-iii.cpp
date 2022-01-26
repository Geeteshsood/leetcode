class Solution {
public:
    
    bool find(int i,vector<int> &arr,vector<bool> &vis){
        
        if(i < 0 || i >= arr.size() || vis[i])return false;
        
        vis[i] = true;
        
        if(arr[i] == 0)return true;
        
        bool f1 = find(i + arr[i],arr,vis);
        bool f2 = find(i - arr[i],arr,vis);
        
        return f1 || f2;
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<bool> vis(n);
        
        return find(start,arr,vis);
    }
};