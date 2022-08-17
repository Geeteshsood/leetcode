class Solution {
public:
    typedef long long ll;
    
    vector<bool> canEat(vector<int>& cand, vector<vector<int>>& que) {
        
        ll n = que.size(),m = cand.size();
        vector<bool> ans(n,false);
        
        vector<ll> pre(m);
        
        for(ll i=0;i<m;i++){
            if(i != 0)pre[i] = pre[i-1] + cand[i];
            else pre[i] = cand[i];
        }
        
        for(ll i=0;i<que.size();i++){
            
            ll type = que[i][0] , day  = que[i][1] , lim = que[i][2];
            
            ll sum = 0;
            // cout<<pre[type-1]<<" "<<cand[type]<<endl;
            
            if(type != 0)sum = pre[type-1];

            ll minday = (sum/lim);
            ll maxday = pre[type]-1; // we start from day 0;
            
            // cout<<minday<<" "<<maxday<<endl;
            ans[i] = day>=minday && day<=maxday;
        }
        
        return ans;
    }
};