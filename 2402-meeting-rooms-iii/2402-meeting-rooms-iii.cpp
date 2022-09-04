class Solution {
public:
    typedef long long ll;
    
    typedef vector<ll> vv;
    
    int mostBooked(ll n, vector<vector<int>>& nums) {
        
        ll m = nums.size();
        vector<ll> meet(n);
        
        sort(nums.begin(),nums.end());
        
        priority_queue<vv,vector<vv>,greater<vv>> pq; // endTime , room , startTime.
        priority_queue<ll,vector<ll>,greater<ll>> av; // for avalaiblem rooms.
        
        for(ll i=0;i<n;i++){ // all avalaible rooms.
            av.push(i);
        }
        
        for(ll i=0;i<m;i++){
                   
            ll sm = (ll)nums[i][0] , em = (ll)nums[i][1];
            
            while(pq.size() && sm >= pq.top()[0]){    // free all the rooms in which meeting is over before 
                                                      // new meeting .
                ll start = pq.top()[2] , end = pq.top()[0] , rm = pq.top()[1];
                
                pq.pop();
                av.push(rm);
                
            }
            
            if(av.empty()){     // if no room is available then wait.
                
                ll start = pq.top()[2] , end = pq.top()[0] , rm = pq.top()[1];
                
                pq.pop();
                pq.push({end + em-sm,rm,end});
                meet[rm]++;
                
            }
            else{               // allot in minimum number room.
              ll rm = av.top();
              av.pop();
                
              meet[rm]++;
              pq.push({em,rm,sm});
            }
        }
        
        ll mini = -1 , ans = -1;
        
        for(ll i=0;i<n;i++){
            if(meet[i] > mini){
                mini = meet[i];
                ans = i;
            }
        }
       
        return ans;
    }
};