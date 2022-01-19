class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       
        int n = nums.size();
        unordered_map<long, int> dp[max(1, (int)nums.size())];
        
        long sum = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff = (long)nums[i] - (long)nums[j];
                dp[i][diff] += dp[j][diff] + 1;
                
                sum += dp[j][diff];
            }
        }
     
        return sum;
    }
};