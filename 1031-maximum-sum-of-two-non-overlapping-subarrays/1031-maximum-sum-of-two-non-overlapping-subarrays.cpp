class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        
        int n = nums.size();
        
        for(int i=1;i<n;i++){
           nums[i] += nums[i-1];
        }
        
        int ans = nums[f+s-1] , lmax = nums[f-1] , rmax = nums[s-1] , lsum = 0 , rsum = 0;
        
        for(int i=f+s;i<n;i++){
            rsum = nums[i] - nums[i-s];                // second subarray sum
            lmax = max(lmax,nums[i-s]-nums[i-s-f]);   //  first subarray maximum sum to its left
            
            lsum = nums[i] - nums[i-f];               // first subarray sum
            rmax = max(rmax,nums[i-f]-nums[i-s-f]);   // second subarray maximum sum to its left
            
            ans = max({ans,rsum + lmax,lsum + rmax});
        }
       
     return ans;   
    }
};