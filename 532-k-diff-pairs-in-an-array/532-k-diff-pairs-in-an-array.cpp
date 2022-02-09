class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size();
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
             
             while(i > 0 && i< n && nums[i] == nums[i-1])i++;
            
             if(i == n)break;
            
             int num = nums[i] + k;
            
             auto it = lower_bound(nums.begin() + i + 1,nums.end(),num) - nums.begin();
            
             if(it < n && nums[it] == num)cnt++;
        }
        
     return cnt;
    }
};