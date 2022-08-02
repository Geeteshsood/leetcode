class Solution {
public:
    
   int quickselect(int start , int end,vector<int> &nums,int k){
        
        if(start >= end)return nums[start];
       
        int n = nums.size();

        int i = start , j = start;
       
        while(i <= end){
            
            if(nums[i] <= nums[end]){
                swap(nums[i],nums[j]);
                i++,j++;
            }
            else if(nums[i] > nums[end]){
                 i++;
            }
        }
        
        int idx = j-1;
       
        if(idx > k){
            return quickselect(start,idx-1,nums,k);
        }
        else if(idx < k){
            return quickselect(idx+1,end,nums,k);
        }
       
         return nums[idx];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        k =  n - k;
        
        return quickselect(0,n-1,nums,k);
        
    }
};