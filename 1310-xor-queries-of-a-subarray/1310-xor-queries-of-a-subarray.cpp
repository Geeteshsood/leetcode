class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        
        int Xor = 0;
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            Xor = Xor^arr[i];
            dp[i] = Xor;
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        
        int m = queries.size();
        
        vector<int> ans(m);
        
        for(int i=0;i<m;i++){
            
            int x = queries[i][0] , y = queries[i][1];
         
            if(x > 0)ans[i] = dp[y]^dp[x-1];
            else {
                // cout<<i<<" "<<y<<endl;
                ans[i] = dp[y];
            }
        }
       
        return ans;
    }
};