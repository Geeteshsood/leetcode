class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        
        int n = ques.size();
        long long val = 0,x=0;
        
        vector<long long> dp(n,0);
        
        for(int i = n-1 ; i>=0 ; i--){
            int j = ques[i][1];
            if(i+j+1 > n-1){
                val = max(val,(long long)ques[i][0]);
            }else{
                x = (long long)ques[i][0] + dp[i+j+1];
                val = max(val,x);
            }
            dp[i] = val;
            // cout<<val<<" ";
            
        }
        // cout<<"\n";
        
        return val;
    }
};