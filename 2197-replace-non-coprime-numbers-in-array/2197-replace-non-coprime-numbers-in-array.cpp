class Solution {
public:
    
    typedef long long ll;
    
    ll gcd(ll a,ll b){
        
        if(b == 0)return a;
        
        return gcd(b,a%b);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        stack<ll> st;
        ll n = nums.size();
        
        for(ll i=0;i<n;i++){
            
            ll cur = (ll)nums[i];
            
            while(st.size()){
                
             
               ll gcd1 = gcd(cur,st.top());
                
               if(gcd1 > 1){
                   ll lcm = (cur*st.top())/gcd1;
                   st.pop();
                   cur = lcm;
               }
               else break;
            }
            
            st.push(cur);
        }
        
        int sz = st.size();
        
        vector<int> ans(sz);
        
        while(st.size()){
            ans[sz-1] = st.top();
            st.pop();
            sz--;
        }
       
        return ans;
    }
};