class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        unordered_set<int> s;
        int n = days.size();
        
        for(int i=0;i<n;i++){
            s.insert(days[i]);
        }
        
        vector<int> dp(366);
        
        for(int i=1;i<=365;i++){
            
            if(s.count(i)){
                
                int val1 = 0 , val2 = 0;
                
                if(i>=30)val1 = dp[i-7] , val2 = dp[i-30];
                else if(i>=7)val1 = dp[i-7];
                
                dp[i] = min({costs[0] + dp[i-1] , costs[1] + val1 , costs[2] + val2});
             
            }
            else dp[i] = dp[i-1];
        }
        
       return dp[365];
    }
};