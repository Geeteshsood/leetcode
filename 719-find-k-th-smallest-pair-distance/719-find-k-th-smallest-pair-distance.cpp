class Solution {
public:
    
    int count(int mid,vector<int> &nums){
        
        int n = nums.size(),cnt = 0;
        
        for(int i=0;i<n;i++){
            
             int low = nums[i] - mid;
            int high = nums[i] + mid;
            
            int y = upper_bound(nums.begin(),nums.end(),high) - nums.begin();
            
            cnt += (y-i-1);
            
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
            
           int cnt = count(mid,nums);
            
            // cout<<mid<<" "<<cnt<<endl;
            
           if(cnt >= k){
               ans = mid;
               end = mid-1;
           }
           else start = mid+1;
            
        }
        
        return ans;
    }
};