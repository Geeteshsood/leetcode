class Solution {
public:
    
    typedef long long ll;
    
    ll find(ll min,ll sec,ll startAt,ll moveCost,ll pushCost){
        
        string str;
        
         if(min < 100){

            if(sec/10 == 0){
                if(min == 0)str = to_string(sec) ;
                else str = to_string(0) + to_string(sec);
            }
            else{
                str = to_string(sec);
            }
            // cout<<str<<endl;
            if(min > 0){
                str = to_string(min) + str;
            }
         }
        
         // cout<<str<<endl;
         ll cost = 0;
        
         for(ll i=0;i<str.size();i++){
             
             // cout<<str[i]<<" , "<<startAt<<endl;
             
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
        
        ll min1 = ts/s;
        ll sec1 = ts%s;
        
        ll min2 = min1-1;
        ll sec2 = sec1 + s;
        
         ll x = INT_MAX , y = INT_MAX;
        
         if(min1<100)x = find(min1,sec1,startAt,moveCost,pushCost);
        
         if(min2 >= 0 && sec2 < 100){
             y = find(min2,sec2,startAt,moveCost,pushCost);
         }
        
    return (ll)min(x,y);      
    }
};