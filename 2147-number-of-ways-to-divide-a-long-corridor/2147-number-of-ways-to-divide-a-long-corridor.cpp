class Solution {
public:
    typedef long long ll;
    
    int numberOfWays(string s) {
        
        ll mod = 1e9 + 7;
        ll n = s.size() , pro = 1 , cnt = 0;
        
        ll sum = 0 , y = -1 , x = -1;
        
        for(int i=0;i<n;i++){
            
            if(s[i] == 'S'){
                sum++;
                cnt++;
                if(cnt == 1)y = i;
            }
            
            if(cnt == 2){
                if(x != -1)pro = (pro * (y-x))%mod;
                x = i;
                cnt = 0;
            }
            
        }
        
        if(cnt != 0)return 0;
        
        if(sum == 2)return 1;
        if(sum == 0)return 0;
        
        return pro%mod;
    }
};