class Solution {
public:
    
    int minimumTime(string s) {
        
        int ans = INT_MAX;
        int n = s.size();
        
        vector<int> cost(n);
        
        cost[n-1] = s[n-1]-'0';
        
        for(int i=n-2;i>=0;i--){
            
            cost[i] = min(2*(s[i]-'0') + cost[i+1] , n-i);
        }
        
        for(int left=-1;left<n-1;left++){
            
            ans = min(ans,left + 1 + cost[left+1]);
            
        }
        
       return min(n,ans);
    }
};