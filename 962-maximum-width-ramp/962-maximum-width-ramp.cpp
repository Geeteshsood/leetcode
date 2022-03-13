class Solution {
public:
    
    int search(int i,vector<int> & arr,vector<int> &nums){
        
        int start = 0 , end = arr.size()-1 , ans = -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(nums[arr[mid]] >= nums[i]){
                ans = arr[mid];
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
    
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size() , ans = INT_MIN;
        
        vector<int> arr({n-1});
        
        for(int i=n-2;i>=0;i--){
            
            int idx = search(i,arr,nums);
            
            if(idx != -1)ans = max(ans,idx-i);
            
            if(nums[i] > nums[arr.back()]){
                arr.push_back(i);
            }
        }
        
        return ans==INT_MIN?0:ans;
    }
};