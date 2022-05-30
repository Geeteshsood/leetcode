class Solution {
public:
    typedef long long ll;
    
    int divide(ll dividend, ll divisor) {
        
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        
        ll y = dividend  , x = divisor;
        
        bool set = false;
        
        if(y < 0 && x < 0){}
        else if(y < 0)set = true;
        else if(x < 0)set = true;
        
        dividend = abs(dividend) , divisor = abs(divisor);
        y = labs(y) , x = labs(x);
        
        ll cnt = 1 , ans = 0;
        
        while(y >= x){
            // cout<<y<<" "<<x<<endl;
            if(y < (x<<1)){
                y -= x;
                x = divisor;
                ans += cnt;
                cnt = 1;
            }
            else{
              x = x<<1;
              cnt = cnt<<1;
            }
        }
        
        if(set)ans = -ans;
        
      return ans;  
    }
};