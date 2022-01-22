typedef long long ll;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        
        ll sum = 0 , ans = 0;
        
        for(auto &x:bat){
            sum += (ll)x;
        }
        
        ll low = 0 , high = sum;
        
        while(low <= high){
            
            ll mid = high - (high - low)/2;
            ll time = mid*n , cnt = 0;
            
            for(auto &x:bat){
                cnt += min((ll)x,mid);
            }
            
            if(cnt >= time){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        
     return ans;    
    }
};