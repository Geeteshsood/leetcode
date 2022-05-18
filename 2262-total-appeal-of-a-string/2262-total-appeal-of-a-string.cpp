class Solution {
public:
    typedef long long ll;
    
    long long appealSum(string s) {
        
        ll n = s.size();
        unordered_map<char,ll> mp;
        
        vector<ll> dp(n);
        
        for(char ch='a';ch<='z';ch++){
            mp[ch] = -1;
        }
        
        for(ll i=0;i<n;i++){
            
            if(i!=0)dp[i] = dp[i-1] + i-mp[s[i]];
            else dp[i] = 1;
            
            mp[s[i]] = i;
        }
       
        ll sum = 0;
        
        for(ll i=0;i<n;i++){
            sum += dp[i];
        }
        
        return sum;
    }
};