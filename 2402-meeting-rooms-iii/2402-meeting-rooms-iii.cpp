class Solution {
public:
    typedef long long ll;
    
    typedef vector<ll> vv;
    
    int mostBooked(ll n, vector<vector<int>>& nums) {
        
        ll m = nums.size();
        vector<ll> meet(n);
        
        sort(nums.begin(),nums.end());
        
        priority_queue<vv,vector<vv>,greater<vv>> pq;
        priority_queue<ll,vector<ll>,greater<ll>> av;
        
        for(ll i=0;i<n;i++){
            av.push(i);
        }
        
        for(ll i=0;i<m;i++){
            
            if(pq.empty()){
                ll sm = (ll)nums[i][0] , em = (ll)nums[i][1];
                ll rm = av.top();
                av.pop();
                pq.push({em,rm,sm});
                meet[rm]++;
                continue;
            }
            
            ll sm = (ll)nums[i][0] , em = (ll)nums[i][1];
            
            while(pq.size() && sm >= pq.top()[0]){
                
                ll start = pq.top()[2] , end = pq.top()[0] , rm = pq.top()[1];
                
                pq.pop();
                av.push(rm);
                
            }
            
            if(av.empty()){
                
                ll start = pq.top()[2] , end = pq.top()[0] , rm = pq.top()[1];
                
                pq.pop();
                pq.push({end + em-sm,rm,end});
                meet[rm]++;
                
            }
            else{
              ll rm = av.top();
              av.pop();
                
              meet[rm]++;
              pq.push({em,rm,sm});
            }
        }
        
        ll mini = -1 , ans = -1;
        
        for(ll i=0;i<n;i++){
            // cout<<meet[i]<<endl;
            if(meet[i] > mini){
                mini = meet[i];
                ans = i;
            }
        }
       
        return ans;
    }
};