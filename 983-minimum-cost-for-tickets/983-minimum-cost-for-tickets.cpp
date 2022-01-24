class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size() , idx = 0;
        
        vector<int> dp(366);
        
        for(int i=1;i<=365;i++){
            
            if(idx<n && i == days[idx]){
                
                int val1 = 0 , val2 = 0;
                
                if(i>=30)val1 = dp[i-7] , val2 = dp[i-30];
                else if(i>=7)val1 = dp[i-7];
                
                dp[i] = min({costs[0] + dp[i-1] , costs[1] + val1 , costs[2] + val2});
                
                idx++;
            }
            else dp[i] = dp[i-1];
        }
        
       return dp[365];
    }
};