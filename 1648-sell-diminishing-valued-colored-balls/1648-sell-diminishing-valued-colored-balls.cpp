typedef long long ll;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        
        sort(inventory.begin(),inventory.end());
        
        ll order = (ll)orders;
        
        ll mod = 1e9 + 7;
        vector<ll> nums;
        nums.push_back((ll)0);
        
        for(ll i=0;i<inventory.size();i++){
            nums.push_back((ll)inventory[i]);
        }
        
        ll n = (ll)inventory.size() + 1 , sum = 0;
        ll j = n-1;
        
        for(ll i = j-1;i>=0;i--){
            
            ll len = j-i;
            ll val = (len*(nums[j]-nums[i]));
            
            if(val < 0)val += mod;
            
            if(val < order){
                
                ll y = nums[j] , x = nums[i];

                sum += ( len*((y*(y+1))-(x*(x+1))) )/2;
                order -= val;
            }
            else{
                 ll y = nums[j] , rem = order%len;
                 ll x = y - (order/len);

                 sum += ( len*((y*(y+1))-(x*(x+1))) )/2;
                 sum += (rem*x);
                
                 order = 0;
                 break;
            }
            nums[j] = nums[i];
        }
        
        sum = sum%mod;
        if(sum < 0)sum += mod;
        
      return sum;  
    }
};