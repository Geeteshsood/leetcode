typedef long long ll;

class Solution {
public:
    int maxProfit(vector<int>& nums, int order) {
        
        sort(nums.rbegin(),nums.rend());
        
        nums.push_back(0);
        int n = nums.size() ;
        ll sum = 0 , mod = 1e9 + 7;
        
        for(int i=1;i<n;i++){
            
            ll val = i*(nums[0]-nums[i]);
            
            if(val < order){
                
                ll y = nums[0] , x = nums[i];

                sum += ( i*((y*(y+1))-(x*(x+1))) )/2;
                
                order -= val;
            }
            else{
                 ll y = nums[0] , rem = order%i;
                 ll x = y - (order/i);

                 sum += ( i*((y*(y+1))-(x*(x+1))) )/2;
                 sum += (rem*x);
                
                 break;
            }
            nums[0] = nums[i];
        }
        
        sum = sum%mod;
        if(sum < 0)sum += mod;
        
      return sum;  
    }
};