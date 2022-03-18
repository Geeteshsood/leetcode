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
        
        stack<ll> st1,st2;
        
        for(ll i=0;i<n;i++){
            st1.push((ll)nums[i]);
        }
        ll sz = n;
        
        while(true){
            
            if(st1.size() >= 2){
                ll x = st1.top();
                st1.pop();
                ll y = st1.top();
                st1.pop();
                
                // cout<<x<<" "<<y<<endl;
                ll gcd1 = gcd(x,y);
            
                if(gcd1 > 1){
                    ll lcm = (x*y)/gcd1;
                    st1.push(lcm);
                }
                else st1.push(y),st2.push(x);
            }
            else if(st1.size() == 1){
                odd++;
                st2.push(st1.top());
                st1.pop();
                if(st2.size() == sz)break;
                st1 = st2;
                sz = st2.size();
                while(st2.size())st2.pop();
            }
            
        }
        
        vector<int> ans;
        
        while(st2.size()){
            ans.push_back(st2.top());
            st2.pop();
        }
        if(odd%2 == 0)reverse(ans.begin(),ans.end());
        
        return ans;
    }
};