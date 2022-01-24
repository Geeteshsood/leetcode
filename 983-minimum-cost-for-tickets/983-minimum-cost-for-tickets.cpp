class Solution {
public:
    
     unordered_set<int> s;
    
    int find(int i,vector<int> &costs,vector<int> &dp){
      
        if(i > 365)return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int val = 0;
        
        if(s.count(i)){
    val = min({costs[0] + find(i+1,costs,dp) , costs[1] + find(i+7,costs,dp) , costs[2] + find(i+30,costs,dp)});
        }
        else val = find(i+1,costs,dp);
         
      return dp[i] = val;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> dp(366,-1);
        
        for(auto &i:days){
            s.insert(i);
        }
        
        return find(0,costs,dp);
    }
};