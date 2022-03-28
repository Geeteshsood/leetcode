class Solution {
public:
    
    typedef long long ll;
    
    ll find(ll len,ll que){
        
        if(len == 1)return que-1;
        else if(len == 2){
            que = que-1;
            
            return que*10 + que;
        }
        
        ll x = ((len-2)-1)/2;
        
        ll set = pow(10,x+1);
        
        ll grp = (que-1)/set;
        
        if(que%set == 0)que = set;
        else que = que%set;
        
        ll ans = find(len-2,que);
      
        return (grp*pow(10,len-2) + ans)*10 + grp;
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, ll len) {
        
        vector<ll> res;
        
        if(len == 1){
            for(auto &que : queries){
                if(que > 9)res.push_back(-1);
                else res.push_back((ll)que);
            }
            return res;
        }
        if(len == 2){
             for(auto &que : queries){
                if(que>9)res.push_back(-1);
                else res.push_back((ll)((ll)que*10 + que));
            }
            return res;
        }
        
        ll x = ((len-2)-1)/2;
        
        ll set = pow(10,x+1);
        
        for(auto &it : queries){
            
            ll que = (ll)it;
            
            if(que > set*9){
                res.push_back(-1);
                continue;
            }
            
            ll grp = ((que-1)/set) + 1;
            
            if(que%set == 0)que = set;
            else que = que%set;
            
            ll ans = find(len-2,que);
            
            // cout<<grp<<" "<<ans<<" "<<que<<endl;
            
            ll val = (grp*pow(10,len-2) + ans)*10 + grp;
            
            res.push_back(val);
        }
        
        return res;
    }
};