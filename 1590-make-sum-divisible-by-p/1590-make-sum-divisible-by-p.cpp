class Solution {
public:
    typedef long long ll;
    
    int minSubarray(vector<int>& nums, ll p) {
        
        ll n = nums.size() , total = 0;
        
        for(ll i=0;i<n;i++){
            total += nums[i];
        }
        
        ll r = total%p;
        
        if(r == 0)return 0;
        
        unordered_map<ll,ll> mp;
        mp[0] = -1;
        
        ll sum = 0 , len = n;
        
        for(ll i=0;i<n;i++){
            
            sum += nums[i];
            
            ll val = ((sum%p - r) + p)%p;
            
            if(mp.find(val) != mp.end()){
                len = min(len , i - mp[val]);
            }
            
            mp[sum%p] = i;
            
        }
        
        if(len == n)return -1;
        
        return len;
    }
};