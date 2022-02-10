class Solution {
public:
    typedef long long ll;
    
    long long minimumDifference(vector<int>& nums) {
        
        ll n = nums.size()/3;
        vector<ll> left(n + 1),right(n + 1);
        
        ll sum = 0;
        priority_queue<ll> pq;
        
        for(ll i=0;i<n;i++){
            pq.push((ll)nums[i]);
            sum += (ll)nums[i];
        }
        
        left[0] = sum;
        
        for(ll i=n;i<2*n;i++){
            if((ll)nums[i] < pq.top()){
                sum -= pq.top();
                pq.pop();
                pq.push((ll)nums[i]);
                sum += (ll)nums[i];
            }
            
            left[i-n+1] = sum;
        }
        
        priority_queue<ll,vector<ll>,greater<ll>> pqq;
        
        sum = 0;
        
        for(ll i=3*n-1;i>=2*n;i--){
            pqq.push((ll)nums[i]);
            sum += (ll)nums[i];
        }
        
        right[n] = sum;
        
        for(ll i=2*n-1;i>=n;i--){
            if((ll)nums[i] > pqq.top()){
                sum -= pqq.top();
                pqq.pop();
                pqq.push((ll)nums[i]);
                sum += (ll)nums[i];
            }
            
            right[i-n] = sum;
        }
        // cout<<"**"<<endl;
        ll ans = LLONG_MAX;
        
        for(int i=0;i<=n;i++){
            ans = min(ans,left[i] - right[i]);
        }
        
        return ans;
    }
};