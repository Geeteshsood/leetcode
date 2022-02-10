class Solution {
public:
    typedef long long ll;
    
    long long minimumDifference(vector<int>& nums) {
        
        ll n = nums.size()/3;
        vector<ll> left(3*n),right(3*n);
        
        ll sum = 0;
        priority_queue<ll> pq;
        
        for(ll i=0;i<n;i++){
            pq.push((ll)nums[i]);
            sum += (ll)nums[i];
            left[i] = sum;
        }
        
        for(ll i=n;i<2*n;i++){
            if((ll)nums[i] < pq.top()){
                sum -= pq.top();
                pq.pop();
                pq.push((ll)nums[i]);
                sum += (ll)nums[i];
            }
            
            left[i] = sum;
        }
        
        priority_queue<ll,vector<ll>,greater<ll>> pqq;
        
        sum = 0;
        
        for(ll i=3*n-1;i>=2*n;i--){
            pqq.push((ll)nums[i]);
            sum += (ll)nums[i];
            right[i] = sum;
        }
        
        for(ll i=2*n-1;i>=n;i--){
            if((ll)nums[i] > pqq.top()){
                sum -= pqq.top();
                pqq.pop();
                pqq.push((ll)nums[i]);
                sum += (ll)nums[i];
            }
            
            right[i] = sum;
        }
        // cout<<"**"<<endl;
        ll ans = LLONG_MAX;
        
        for(ll i=n-1;i<2*n;i++){
            
            ans = min(ans , left[i] - right[i+1]);
            
        }
        
        return ans;
    }
};