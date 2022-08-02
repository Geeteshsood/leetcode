class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0 , end = n-1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(mid < n-1 && nums[mid] == nums[mid+1]){
                
                if(mid%2 == 0)start = mid + 2;
                else end = mid-1;
            }
            else if(mid > 0 && nums[mid] == nums[mid-1]){
                
                if(mid%2 == 0)end = mid - 2;
                else start = mid+1;
            }
            else return nums[mid];
        }
        
        return -1;
    }
};