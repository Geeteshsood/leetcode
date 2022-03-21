class Solution {
public:
    typedef long long ll;

    ll nthUglyNumber(ll n, ll a, ll b, ll c) {
        
        ll start = 1 , end = 2*1e9 , ans = -1;
        
        ll ab = (a*b)/__gcd(a,b);
        ll bc = (b*c)/__gcd(b,c);
        ll ac = (a*c)/__gcd(a,c);
        ll abc = (ab*c)/__gcd(ab,c);
        
        while(start <= end){
            
            ll mid = start + (end - start)/2;
            
            ll rank = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
            
            if(rank < n){
                start = mid + 1;
            }
            else{
                ans = mid;
                end = mid-1;
            }
            
        }
        
        return ans;
    }
};