class Solution {
public:
    typedef long long ll;
    
    long long appealSum(string s) {
        
        ll n = s.size();
        vector<int> pos(26,-1);
        
        vector<ll> dp(n);
        
        for(ll i=0;i<n;i++){
            
            if(i!=0)dp[i] = dp[i-1] + i-pos[s[i]-'a'];
            else dp[i] = 1;
            
            pos[s[i]-'a'] = i;
        }
       
        ll sum = 0;
        
        for(ll i=0;i<n;i++){
            sum += dp[i];
        }
        
        return sum;
    }
};