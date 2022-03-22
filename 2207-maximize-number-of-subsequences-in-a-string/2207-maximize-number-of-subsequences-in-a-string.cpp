class Solution {
public:
    typedef long long ll;
    
    ll find(string &s,string &p){
        
        ll n = s.size();
        
        ll cnt = 0 , val = 0;
        
        for(ll i=n-1;i>=0;i--){
            if(s[i] == p[1]){
                cnt++;
            }
            if(s[i] == p[0]){
               val += cnt;
            }
        }
        
        if(p[0] == p[1]){
            return val - cnt;
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