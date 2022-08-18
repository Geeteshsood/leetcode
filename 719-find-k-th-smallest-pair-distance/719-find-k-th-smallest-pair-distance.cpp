class Solution {
public:
    
    int count(int mid,vector<int> &nums){
        
        int n = nums.size();
        int left = 0 , cnt = 0;
        
        for(int right=0;right<n;right++){
            
            while(nums[right] - nums[left] > mid)left++;
            
            cnt += (right-left);
            
        }
        
      return cnt;  
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int start = 0;
        int end = nums[n-1]-nums[0];
        int ans = -1;
        
        while(start <= end){
            
           int mid = start + (end - start)/2;
            
           if(count(mid,nums) >= k){
               ans = mid;
               end = mid-1;
           }
           else start = mid+1;
            
        }
        
        return ans;
    }
};