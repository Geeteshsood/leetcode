class Solution {
public:
    typedef long long ll;
    
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        unordered_map<ll,ll> mp;
        
        for(ll i=0;i<n;i++){
            mp[edges[i]] += i;
        }
        
        ll idx = -1 , res = INT_MIN;
        
        for(auto &[key,val] : mp){
            if(res < val){
                res = val;
                idx = key;
            }
            else if(res == val){
                if(key < idx){
                    idx = key;
                }
            }
        }
        
        return idx;
    }
};