class Solution {
public:
    typedef long long ll;
    
    ll check(vector<int> &time,ll x){
        
        ll val = 0;
        for(auto &i : time){
            val += x/(ll)i;
        }
        
      return val;  
    }
    
    long long minimumTime(vector<int>& time, int k) {
        
        
        ll start = 1,end = 1e14;
        ll ans = 0;
        
        while(start <= end){
           
          ll mid = start + (end-start)/2;
            
          ll val = check(time,mid);
            
          if(val < k){
              start = mid + 1;
          }
          else{
              ans = mid;
              end = mid-1;
          }
            
        }
        
       return ans; 
    }
};