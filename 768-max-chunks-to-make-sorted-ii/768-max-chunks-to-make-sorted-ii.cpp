class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> lmax(n),rmin(n);
        
        lmax[0] = arr[0];
        for(int i=1;i<n;i++){
            lmax[i] = max(lmax[i-1],arr[i]);
        }
        
        rmin[n-1] = INT_MAX;
        
        for(int i=n-2;i>=0;i--){
            rmin[i] = min(arr[i+1],rmin[i+1]);
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            if(lmax[i] <= rmin[i])cnt++;
        }
        
        return cnt;
    }
};