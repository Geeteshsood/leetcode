class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
        
        int n = nums.size() ,sum = 0;
        vector<int> left(n),right(n);
        
        for(int i=0;i<fl;i++){
            sum += nums[i];
        }
        
        left[fl-1] = sum;
        
        for(int i=fl;i<n;i++){
            sum += nums[i] - nums[i-fl];
            left[i] = max(left[i-1],sum);
        }
        
        sum = 0;
        
        for(int i=n-1;i>=n-fl;i--){
            sum += nums[i];
        }
        
        right[n-fl] = sum;
        
        for(int i=n-fl-1;i>=0;i--){
            sum += nums[i]-nums[i+fl];
            right[i] = max(right[i+1],sum);
        }
        
        sum = 0;
        for(int i=0;i<sl;i++){
            sum += nums[i];
        }
        
        int ans = sum + right[sl];
        
        for(int i=sl;i<n-1;i++){
            sum += nums[i]-nums[i-sl];
            ans = max(ans,sum + max(right[i+1],left[i-sl]));
        }
        
        sum += nums[n-1]-nums[n-1-sl];
        ans = max(ans,sum + left[n-1-sl]);
        
        return ans;
    }
};