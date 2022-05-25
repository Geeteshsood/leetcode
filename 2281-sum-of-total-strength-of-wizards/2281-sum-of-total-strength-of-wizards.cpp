class Solution {
public:
    typedef long long ll;
    
    int totalStrength(vector<int>& arr) {
        
        ll mod = 1e9 + 7;
        
        ll n = arr.size();
        vector<ll> pre(n+1),left(n),right(n),dp(n+2);
        
        ll sum = 0;
        
        for(ll i=0;i<n;i++){
            pre[i+1] = (pre[i] + arr[i])%mod;
        }
        for(ll i=0;i<=n;i++){
            dp[i+1] = (dp[i] + pre[i])%mod;
        }
        
        stack<ll> st;

        for(ll i=0;i<n;i++){
            
            while(st.size() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            if(st.size())left[i] = st.top();
            else left[i] = -1;
            
            st.push(i);
        }
        
        while(st.size())st.pop();
        
        for(ll i=n-1;i>=0;i--){
            
            while(st.size() && arr[i] < arr[st.top()]){
                st.pop();
            }
            
            if(st.size())right[i] = st.top();
            else right[i] = n;
            
            st.push(i);
        }

        ll ans = 0;
        
        for(ll i=0;i<n;i++){
            
            ll suml = 0 , sumr = 0;
            
            suml = (dp[i+1] - dp[left[i]+1] + mod)%mod;
            sumr = (dp[right[i]+1] - dp[i+1] + mod)%mod;
            
            ll l = ((right[i]-i)*suml)%mod;
            ll r = ((i-left[i])*sumr)%mod;
            
            ans = (ans + (arr[i]*(r-l))%mod + mod)%mod;
        }
        
        return (ans + mod)%mod;
    }
};