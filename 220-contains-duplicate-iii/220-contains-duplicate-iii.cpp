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
        // for(auto &it : mp){
        //     cout<<it.first<<" * "<<it.second<<endl;
        // }
        //  cout<<endl;
        int j = k+1;
        
     for(int i=1;i<n-1;i++,j++){
         
        if(mp[(ll)nums[i]] == 1)mp.erase((ll)nums[i]);
        else mp[(ll)nums[i]]--;
         
        if(j < n)mp[(ll)nums[j]]++;
    
        int low = nums[i] - t;
        int high = nums[i] + t;
         
        auto it1 = mp.lower_bound(low);
        auto it2 = mp.lower_bound(high);
         
//         cout<<i<<endl;
         
//         for(auto &it : mp){
//             cout<<it.first<<" * "<<it.second<<endl;
//         }
         
//         cout<<endl;
         
        ll val1 = it1->first;
        // cout<<it1->first<<" :: "<<it1->second<<endl;
        it1++;
         
        // cout<<it1->first<<" :: "<<it1->second<<endl;
         
        ll val2 = INT_MAX;
        if(it1 != mp.end())val2 = it1->first;

        ll val3 = it2->first;
        if(it2 != mp.begin())it2--;
         
        ll val4 = INT_MAX;
         
        if(it2->second)val4 = it2->first;
         
        // cout<<i<<" -> "<<val1<<" "<<val2<<" "<<val3<<" "<<val4<<endl;
         
        if(abs(val1-(ll)nums[i]) <= (ll)t)return true;
        if(abs(val2-(ll)nums[i]) <= (ll)t)return true;
        if(abs(val3-(ll)nums[i]) <= (ll)t)return true; 
        if(abs(val4-(ll)nums[i]) <= (ll)t)return true; 
         
     }
    
        return false;
        
    }
};