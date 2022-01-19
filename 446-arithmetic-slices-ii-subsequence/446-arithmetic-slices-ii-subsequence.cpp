class Solution {
public:
        
    int numberOfArithmeticSlices(vector<int>& nums){
      
        int n=nums.size(),ans=0;
        long diff=0;
        vector<unordered_map<long,long>> dp(n);
      
        for(int i=0;i<n;i++){
                
           for(int j=0;j<i;j++){
               diff=(long)nums[i]-(long)nums[j];
                   
               if(dp[j].count(diff)){
                    ans+=dp[j][diff];
                    dp[i][diff]+=dp[j][diff]+1;
               }   
               else dp[i][diff]+=1;
           }
                
        }

return ans;
    }
};