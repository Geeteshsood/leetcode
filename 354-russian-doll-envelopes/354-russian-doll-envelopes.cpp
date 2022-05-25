class Solution {
public:
    
    static bool cmp(vector<int> &a , vector<int> &b){
        
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        
        sort(envelopes.begin(),envelopes.end() , cmp);

        vector<int> dp(n,INT_MAX);
        
        for(int i=0;i<n;i++){
            
            int height = envelopes[i][1];
            
            auto it = lower_bound(dp.begin(),dp.end(),height) - dp.begin();
            dp[it] = height;
        }
        
        for(int i=0;i<n;i++){
            if(dp[i] == INT_MAX)return i;
        }
        
        return n;
    }
};