class Solution {
public:
    
    int find(int i,int j,int sum,vector<int> &nums,vector<int> &dp){
        
        int n = nums.size(),ans = -1 ,mid = 0;
        int start = j, end = n-2;
        
        while(start<=end){
            
            mid = start + (end-start)/2;
            
            int left = dp[mid] - dp[i];
            int right = sum - left;
            
            if(left<=right){
                ans = mid;
                start = mid + 1;
            }
            else end = mid-1;
        }
        
        return ans;
    }
    
    int waysToSplit(vector<int>& nums) {
        
        int mod = 1e9 + 7;
        int n = nums.size() , total = 0;
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            total += nums[i];
            dp[i] = total;
        }
        
        int cnt = 0 , j = 0 ,left = 0;
        
        for(int i=0;i<n-2;i++){
            
            left += nums[i];
            int val = 2*left;
            
            j = lower_bound(dp.begin() + i + 1,dp.end(),val) - dp.begin();

            int k = find(i,j,total - dp[i],nums,dp);
            if(k != -1)cnt = (cnt + k - j + 1)%mod;
        }
        
       return cnt; 
    }
};