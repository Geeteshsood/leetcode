class Solution {
public:
    typedef long long ll;
    
    long long appealSum(string s) {
        
        ll n = s.size() , sum = 0 , cur = 0 , prev = 0;
        vector<int> pos(26,-1);
        
        for(ll i=0;i<n;i++){
            
            if(i!=0)cur = prev + i-pos[s[i]-'a'];
            else cur = 1;
            
            pos[s[i]-'a'] = i;
            sum += cur;
            prev = cur;
        }

        return sum;
    }
};