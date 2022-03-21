class Solution {
public:
    typedef long long ll;
    
    ll findRank(ll value,ll a,ll b,ll c,ll x,ll y,ll z,ll w){
        
        int rank = 0;
        
        if(value % a == 0)rank += (value/a)-1;
        else rank += value/a;
        
        if(value % b == 0)rank += (value/b)-1;
        else rank += value/b;
        
        if(value % c == 0)rank += (value/c)-1;
        else rank += value/c;
        
        if(value % x == 0)rank -= ((value/x)-1);
        else rank -= (value/x);  
        
        if(value % y == 0)rank -= ((value/y)-1);
        else rank -= (value/y); 
        
        if(value % z == 0)rank -= ((value/z)-1);
        else rank -= (value/z); 
        
        if(value % w == 0)rank += ((value/w)-1);
        else rank += (value/w); 
        
        return rank;
    }
    
    ll nthUglyNumber(ll n, ll a, ll b, ll c) {
        
        ll start = 1 , end = 2*1e9 , set = -1;
        
        ll x = (a*b)/__gcd(a,b);
        ll y = (b*c)/__gcd(b,c);
        ll z = (a*c)/__gcd(a,c);
        
        ll k = (a*b)/__gcd(a,b);
        ll w = (k*c)/__gcd(k,c);
        
        while(start <= end){
            
            ll mid = start + (end - start)/2;
            
            ll value = mid;
            
            ll rank = 1 + findRank(value,a,b,c,x,y,z,w);
            
            // cout<<mid<<" , "<<rank<<endl;
            
            if(rank < n){
                start = mid + 1;
            }
            else if(rank > n){
                end = mid - 1;
            }
            else{
                if(value%a == 0 || value%b == 0 || value%c == 0)return mid;
                
                set = value;
                break;
            }
            
        }
      
        if(set == -1)return -1;
        
        if(findRank(a*((set/a)-1),a,b,c,x,y,z,w) == n-1)return a*((set/a)-1);
        if(findRank(a*((set/a)+1),a,b,c,x,y,z,w) == n-1)return a*((set/a)+1);
        if(findRank(b*((set/b)-1),a,b,c,x,y,z,w) == n-1)return b*((set/b)-1);
        if(findRank(b*((set/b)+1),a,b,c,x,y,z,w) == n-1)return b*((set/b)+1);
        if(findRank(c*((set/c)-1),a,b,c,x,y,z,w) == n-1)return c*((set/c)-1);
        if(findRank(c*((set/c)+1),a,b,c,x,y,z,w) == n-1)return c*((set/c)+1);
        
        return -1;
    }
};