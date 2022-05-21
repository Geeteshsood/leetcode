class Solution {
public:
    int binarysearch(vector<int>&nums,int low,int high,int target)
    {
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int i=0;
        
        while(i < nums.size()-1 && nums[i]<nums[i+1])
        {
            i++;
        }
        
        i=i+1;
        
        int count1=binarysearch(nums,i,nums.size()-1,target);
        
        int count2=binarysearch(nums,0,i-1,target);
        
        if(count1!=-1)
        {
            return count1;
        }
        else
            return count2;
    }
};