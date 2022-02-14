class Solution {
public:
    
    typedef long long ll;
    
    ll find(ll mint,ll sec,ll startAt,ll moveCost,ll pushCost){
        
        if(min(mint,sec) < 0 || max(mint,sec) >= 100)return INT_MAX;
        
        string str = to_string(mint*100 + sec);
       
         // cout<<str<<endl;
         ll cost = 0;
        
         for(ll i=0;i<str.size();i++){
             
             if((str[i]-'0') != startAt){
                 cost += moveCost;
             }
             
             startAt = str[i]-'0';
         }
        // cout<<cost<<" "<<str<<endl;
        ll len = str.size();
        
        return pushCost*len + cost;
    }
    
    int minCostSetTime(ll startAt, ll moveCost, ll pushCost, ll ts) {
        
        ll s = 60;
        
        ll mint1 = ts/s;
        ll sec1 = ts%s;
        
        ll mint2 = mint1-1;
        ll sec2 = sec1 + s;
        
        
        ll x = find(mint1,sec1,startAt,moveCost,pushCost);
     
        ll y = find(mint2,sec2,startAt,moveCost,pushCost);
        
    return min(x,y); 
        
    }
};