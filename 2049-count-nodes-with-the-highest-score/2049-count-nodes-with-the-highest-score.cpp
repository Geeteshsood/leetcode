class Solution {
public:
    typedef long long ll;
    
    ll ans = INT_MIN , val = INT_MIN , cnt = 0;
    
    ll find(ll node,ll n,vector<vector<ll>> &child){
        
        ll size = child[node].size() , left = 0 , right = 0;
        
        if(size == 2){
            left  =  find(child[node][0],n,child);
            right = find(child[node][1],n,child);
        }
        else if(size == 1){
            left  = find(child[node][0],n,child);
        }
        
        // cout<<node<<" "<<left<<" "<<right<<endl;
        
        ll total = 1 + left + right;
        
        ll rem = n-left-right-1;
        
        if(left == 0)left = 1;
        if(right == 0)right = 1;
        if(rem == 0)rem = 1;
        
        val = left*right*rem;
        // cout<<node<<" "<<val<<endl;
        if(val > ans){
            ans = val;
            cnt = 1;
        }
        else if(val == ans){
            cnt++;
        }
        
     return total;  
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        
        ll n = parents.size();
       
        vector<vector<ll>> child(n,vector<ll>());
        
        for(ll i=0;i<n;i++){
            if(parents[i] != -1)child[parents[i]].push_back(i);
        }
        
        find(0,n,child);
        
        return cnt;
    }
};