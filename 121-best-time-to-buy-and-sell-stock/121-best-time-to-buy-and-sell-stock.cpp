class Solution {
public:
    int maxProfit(vector<int>& price) {
        
        int n = price.size();
        int mini = INT_MAX , ans = INT_MIN;
        
        for(int i=0;i<n;i++){
           ans = max(ans,price[i]-mini);
           mini = min(mini,price[i]);
        }
        
        
        if(ans < 0)return 0;
        
        return ans;
    }
};