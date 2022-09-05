class Solution {
public:
    typedef long long ll;
    
    typedef vector<ll> vv;
    
    int mostBooked(ll n, vector<vector<int>>& nums) {
        
        ll m = nums.size();
        vector<ll> meet(n);
        
        sort(nums.begin(),nums.end());
        
        priority_queue<vv,vector<vv>,greater<vv>> pq; // endTime , room.
        priority_queue<ll,vector<ll>,greater<ll>> avail; // for availalaiblem rooms.
        
        for(ll i=0;i<n;i++){ // all availaible rooms.
            avail.push(i);
        }
        
        for(ll i=0;i<m;i++){
                   
            ll sm = (ll)nums[i][0] , em = (ll)nums[i][1];
            
            while(pq.size() && sm >= pq.top()[0]){    // free all the rooms in which meeting is over before 
                                                      // new meeting .
                ll rm = pq.top()[1];
                
                pq.pop();
                avail.push(rm);
            }
            
            if(avail.empty()){     // if no room is availailable then wait.
                
                ll end = pq.top()[0] , rm = pq.top()[1];
                
                pq.pop();
                pq.push({end + em-sm,rm});
                meet[rm]++;
            }
            else{               // allot in minimum number room.
              ll rm = avail.top();
              avail.pop();
                
              meet[rm]++;
              pq.push({em,rm});
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