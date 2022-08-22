class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> pi;
    
    long long kSum(vector<int>& nums, ll k) {
        
        int n = nums.size();
        ll sum = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] >= 0){
                sum += nums[i];
            }
            else nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(),nums.end());
        
        priority_queue<pi> pq;
        
        ll val = sum;
        pq.push({sum-nums[0],0});
        ll cnt = 1;
        
        while(cnt < k){
            
           auto [sum,i] = pq.top();
           val = sum;
           cnt++;
           pq.pop();   
            
           if(i+1 < n){
             pq.push({sum + nums[i] - nums[i+1],i+1});
             pq.push({sum - nums[i+1],i+1});
           }
        }
        
        return val;
    }
};