class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> nums(arr);
        sort(nums.begin(),nums.end());
        
        int cnt = 0 , j = 0;
        
        for(int i=0;i<n;i++){
            
            while(j < n && arr[i] > nums[j]){
                j++;
            }
            
            if(i == j)cnt++;
        }
        
        return cnt;
    }
};