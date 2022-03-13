class Solution {
public:
    typedef long ll;
    
    typedef pair<ll,ll> pi;
    
    void djikstra(ll src,vector<vector<pi>> &adj,vector<ll> &dist){
        
        ll n = adj.size();
        
        dist[src] = 0;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        pq.push({0,src});

        while(pq.size()){
     
           ll u = pq.top().second;
           ll path = pq.top().first;
           pq.pop();
            
           if(dist[u] != path)continue;
            
           for(auto &it:adj[u]){
               
               ll v =  it.first;
               ll wt = it.second;
               
               if(dist[v] > path + wt){
                   dist[v] = path + wt;
                   pq.push({dist[v],v});
               }
           }
        }
        
    }
    
    long long minimumWeight(ll n, vector<vector<int>>& edges, ll src1, ll src2, ll dest) {
        
        vector<vector<pi>> adj(n) , rev(n);
        
        for(auto &it : edges){
            ll u = (ll)it[0] , v = (ll)it[1] , wt = (ll)it[2];
            
            adj[u].push_back({v,wt});
            rev[v].push_back({u,wt});
        }
        
        vector<ll> dist1(n,LONG_MAX),dist2(n,LONG_MAX),dist3(n,LONG_MAX);
        ll ans = LONG_MAX;
        
        djikstra(src1,adj,dist1);
        djikstra(src2,adj,dist2);
        djikstra(dest,rev,dist3);
    

        for(int i=0;i<n;i++){
            if(dist1[i] != LONG_MAX && dist2[i] != LONG_MAX && dist3[i] != LONG_MAX){
                ans = min(ans,dist1[i] + dist2[i] + dist3[i]);
            }
        }
        
        if(ans == LONG_MAX)ans = -1;
        
     return ans;
    }
};