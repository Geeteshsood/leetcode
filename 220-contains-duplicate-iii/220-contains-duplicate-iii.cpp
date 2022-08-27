class Solution {
public:
    typedef long long ll;
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        
        map<ll,ll> mp;
     
        for(int i=1;i<=min(n-1,k);i++){
            if(abs((ll)nums[0] - (ll)nums[i]) <= t)return true;
            mp[(ll)nums[i]]++;
        }
        
        int j = k+1;
        
     for(int i=1;i<n-1;i++,j++){
         
        if(mp[(ll)nums[i]] == 1)mp.erase((ll)nums[i]);
        else mp[(ll)nums[i]]--;
         
        if(j < n)mp[(ll)nums[j]]++;
    
        int low = nums[i] - t;
         
        auto it1 = mp.lower_bound(low);

        ll val1 = it1->first;

        if(abs(val1-(ll)nums[i]) <= (ll)t)return true;
         
     }
    
        return false;
        
    }
};