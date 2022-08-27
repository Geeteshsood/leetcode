class Solution {
public:
    typedef long long ll;
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, ll t) {
        
        int n = nums.size();
        
        map<ll,ll> mp;
     
        for(int i=1;i<=min(n-1,k);i++){
            
            ll num = nums[i];
            
            if(abs((ll)nums[0] - num) <= t)return true;
            
            mp[num]++;
        }
        
        int j = k+1;
        
     for(int i=1;i<n-1;i++,j++){
         
        ll num = nums[i];
         
        if(mp[num] == 1)mp.erase(num);
        else mp[num]--;
         
        if(j < n)mp[(ll)nums[j]]++;
    
        int low = nums[i] - t;
         
        auto it1 = mp.lower_bound(low);

        ll val1 = it1->first;

        if(abs(val1-num) <= t)return true;
         
     }
    
        return false;
    }
};