class Solution {
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    
    int countNicePairs(vector<int>& nums) {
        
        ll n = nums.size();
        unordered_map<ll,ll> freq;
        
        for(ll i=0;i<n;i++){
            
            string str = to_string(nums[i]);
            reverse(str.begin(),str.end());
            
            ll val = stoi(str);
            freq[nums[i]-val]++;
        }
        
        ll ans = 0;
        
        for(auto &[num,cnt] : freq){
            ans = (ans + ((cnt*(cnt-1))/2)%mod)%mod;
        }
        
        return ans;
    }
};