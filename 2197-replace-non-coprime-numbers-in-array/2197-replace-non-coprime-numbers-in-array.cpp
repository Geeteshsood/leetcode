class Solution {
public:
    typedef long long ll;
    
    ll gcd(ll a,ll b){
        
        if(b == 0)return a;
        
        return gcd(b,a%b);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        ll n = nums.size();
        ll odd = 0;
        
        vector<ll> st1,st2;
        
        for(ll i=0;i<n;i++){
            st1.push_back((ll)nums[i]);
        }
        
        ll sz = n;
        
        while(true){
            
            if(st1.size() >= 2){
                
                ll x = st1.back();
                st1.pop_back();
                ll y = st1.back();
                st1.pop_back();
                
                ll gcd1 = gcd(x,y);
            
                if(gcd1 > 1){
                    ll lcm = (x*y)/gcd1;
                    st1.push_back(lcm);
                }
                else st1.push_back(y),st2.push_back(x);
            }
            else if(st1.size() == 1){
                odd++;
                st2.push_back(st1.back());
                st1.pop_back();
                if(st2.size() == sz)break;
                st1 = st2;
                sz = st2.size();
                st2.clear();
            }
            
        }
        
        vector<int> ans;
        
        for(auto &i : st2){
            ans.push_back(i);
        }
        
        if(odd%2 != 0)reverse(ans.begin(),ans.end());
        
        return ans;
    }
};