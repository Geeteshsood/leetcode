class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0 , end = nums.size()-1;
        
        while(start <= end){
            
           int mid = start + (end - start)/2;
            
         
           if(nums[mid] == target){
               return mid;
           }
           else if(nums[mid] >= nums[start]){
               // first half
               
               if(target >= nums[start]){
                   if(target > nums[mid])start = mid+1;
                   else end = mid-1;
               }
               else {
                    start = mid+1;
               }
           }
           else{
               // second half
               
               if(target < nums[start]){
                   if(target > nums[mid])start = mid+1;
                   else end = mid-1;
               }
               else {
                    end = mid-1;
               }
           }
         
        }
        
        return -1;
    }
};