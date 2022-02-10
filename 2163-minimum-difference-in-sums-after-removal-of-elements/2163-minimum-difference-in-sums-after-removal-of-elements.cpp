class Solution {
public:
    typedef long long ll;
    
    long long minimumDifference(vector<int>& nums) {
        
        ll n = nums.size()/3;
        vector<ll> left(n + 1),right(n + 1);
        
        ll suml = accumulate(nums.begin(),nums.begin()+n,0LL);
        ll sumr = accumulate(nums.begin() + 2*n ,nums.end(),0LL);
        
        priority_queue<ll> pq1(nums.begin(),nums.begin()+n);
        
        priority_queue<ll,vector<ll>,greater<ll>> pq2(nums.begin()+2*n , nums.end());
        
         left[0] = suml;
        right[n] = sumr;
        
        for(ll i=n;i<2*n;i++){
            if(nums[i] < pq1.top()){
                suml = suml - pq1.top() + nums[i];
                pq1.pop();
                pq1.push(nums[i]);
            }
            
            left[i-n+1] = suml;
        }
        
        for(ll i=2*n-1;i>=n;i--){
            if(nums[i] > pq2.top()){
                sumr = sumr - pq2.top() + nums[i];
                pq2.pop();
                pq2.push(nums[i]);
            }
            
            right[i-n] = sumr;
        }

        ll ans = LLONG_MAX;
        
        for(ll i=0;i<=n;i++){
            ans = min(ans,left[i] - right[i]);
        }
        
        return ans;
    }
};