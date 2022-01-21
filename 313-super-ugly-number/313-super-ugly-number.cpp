typedef long long ll;
typedef pair<ll,ll> pi;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
       ll m = primes.size();
       vector<ll> poller(m,0);
       vector<ll> dp(n);
       dp[0] = 1;
        
       priority_queue<pi,vector<pi>,greater<pi>> pq;
      
       for(ll i=0;i<m;i++){
           pq.push({primes[i],i});
       }
       
       for(ll i=1;i<n;i++){
           
           ll val = pq.top().first;
           
           dp[i] = val;
           
           while(pq.top().first == val){
               
               ll j = pq.top().second;
               pq.pop();
               
               poller[j]++;
               ll x = primes[j]*dp[poller[j]];
               
               pq.push({x,j});
           }
       }
       
     return dp[n-1];
    }
};