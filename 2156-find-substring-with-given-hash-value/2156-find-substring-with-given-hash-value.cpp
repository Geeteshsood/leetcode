class Solution {
public:
    typedef long long ll;
    string subStrHash(string s, ll p, ll mod, ll k, ll hashvalue) {
        
            ll n = s.size();
            int idx = 0;
        
            ll val = 0,cnt = 0;
            ll pr = 1;
        
            for(ll i=n-k;i<n;i++){
                val = (val + ((s[i]-'a' + 1)*pr)%mod)%mod;
                if(i < n-1){
                    pr = (pr*p)%mod;
                }
            }
        
            if(val%mod == hashvalue){
                idx = n-k;
            }
        
            for(ll i=n-1,j=n-k-1;j>=0;i--,j--){
                
               ll x = ((s[i]-'a' + 1)*pr)%mod;
                
               val = (val - x + mod)%mod;
                      
               val = (val*p)%mod;
                      
               val = (val + s[j]-'a' + 1)%mod;
                
               if(val == hashvalue){
                   idx = j;
               }
            }
        
        return s.substr(idx,k);
    }
};