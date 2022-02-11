class Solution {
public:
    typedef long long ll;
    string subStrHash(string s, ll p, ll mod, ll k, ll hashvalue) {
        
        ll n = s.size();
        // vector<vector<ll>> dp(n,vector<ll>(n));
        
            string str;
            ll val = 0,cnt = 0;
            ll pr = 1;
        
            for(ll i=n-k;i<n;i++){
                val = (val + ((s[i]-'a' + 1)*pr)%mod)%mod;
                if(i < n-1)pr = (pr*p)%mod;
            }
        
            if(val%mod == hashvalue){
                str = s.substr(n-k,k);
            }
        
            for(ll i=n-1,j=n-k-1;j>=0;i--,j--){
                
               ll x = ((s[i]-'a' + 1)*pr)%mod;
               val = ((val - x)%mod + mod)%mod;
               val = (val*p)%mod;
               val = (val + s[j]-'a' + 1)%mod;
                
               if(val == hashvalue){
                   str = s.substr(j,k);
               }
            }
        
        return str;
    }
};