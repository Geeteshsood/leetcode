class Solution {
public:
    
    int minimumTime(string s) {
        
        int totalcost = INT_MAX;
        int n = s.size();
        
        vector<int> cost(n+1);
        
        for(int i=n-1;i>=0;i--){
            
            cost[i] = min(2*(s[i]-'0') + cost[i+1] , n-i);
            
            totalcost = min(totalcost ,i + cost[i]);
        }

       return min(n,totalcost);
    }
};