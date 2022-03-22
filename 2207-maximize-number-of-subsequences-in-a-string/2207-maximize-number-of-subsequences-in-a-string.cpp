class Solution {
public:
    typedef long long ll;
    
    ll find(string s,string p){
        
        ll n = s.size();
        vector<ll> dp(n);
        
        ll cnt = 0;
        
        for(ll i=n-1;i>=0;i--){
            if(s[i] == p[1]){
                cnt++;
            }
            dp[i] = cnt;
        }

        ll val = 0;
        
        for(ll i=0;i<n;i++){
            if(s[i] == p[0]){
               val += dp[i];
            }
        }
        
        if(p[0] == p[1]){
            return val - dp[0];
        }
       
        return val;
    }
    
    long long maximumSubsequenceCount(string text, string p) {
        
        
        string s1 = p[0] + text;
        string s2 = text + p[1];
        
        ll x = find(s1,p);
        ll y = find(s2,p);
        
        return max(x,y);
    }
};