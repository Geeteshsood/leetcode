class Solution {
public:
    typedef long long ll;
    
    ll cnt = 0 , val = 0 , ans = 0;
    
    ll find(ll node,vector<vector<ll>> &child){
        
        ll n = child.size() , pro = 1 , sum = 0;
        
        for(auto &it : child[node]){
            
            ll cnt = find(it,child);
            
            pro = pro*cnt;
            sum += cnt;
        }
        
        ll rem = n - sum - 1;
        
        if(rem == 0)val = pro;
        else val = pro*rem;
        
        if(val > ans){
            ans = val;
            cnt = 1;
        }
        else if(val == ans)cnt++;
        
        return 1 + sum;
    }
    
    int countHighestScoreNodes(vector<int>& par) {
        
        ll n = par.size();
        vector<vector<ll>> child(n);
        
        for(ll i=0;i<n;i++){
            if(par[i] != -1){
                child[par[i]].push_back(i);
            }
        }
        
        find(0,child);
        
        return cnt;
    }
};