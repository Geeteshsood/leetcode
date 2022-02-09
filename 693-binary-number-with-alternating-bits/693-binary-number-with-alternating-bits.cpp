class Solution {
public:
    typedef long long ll;
    
    bool hasAlternatingBits(int t) {
        
        ll n = (ll)t;
        ll x = n;
        n = n>>1;
        
        n = n^x;
        
        n = n + 1;
        
        ll rsb = n & -n;
    
        return rsb == n;
    }
};