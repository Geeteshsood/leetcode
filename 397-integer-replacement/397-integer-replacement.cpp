class Solution {
public:
    typedef long long ll;
    
    int integerReplacement(int N) {
        
        ll n = (ll)N;
        int cnt = 0;
        
        while(n!=1){
            
            if(n == 3)return cnt + 2;
            
            if(n%2==0)n = n/2;
            else{
                if(n%4 == 1)n = n-1;
                else n = n+1;
            }
            cnt++;
        }
        
        return cnt;
    }
};