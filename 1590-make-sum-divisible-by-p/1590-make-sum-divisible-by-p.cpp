class Solution {
public:
    typedef long long ll;
    
    int minSubarray(vector<int>& nums, ll p) {
        
      unordered_map<ll,vector<ll>> mp;
        
      ll n = nums.size() , sum = 0 , len = 0;
        
      for(ll i=0;i<n;i++){
          sum += nums[i];
          
          mp[sum%p].push_back(i);
          if(sum %p == 0)len = max(len , i+1);
      } 
        
      sum = 0;
    
      for(ll i=n-1;i>=0;i--){
         sum += nums[i];
         ll rem = p-(sum%p);
         
         for(auto &j : mp[rem]){
             if(j < i){
                 len = max(len , n-i + j + 1);
             }
         }
         if(sum%p == 0)len = max(len , n-i);
      }
        
        if(len == 0)return -1;
        
        return n-len;
    }
};