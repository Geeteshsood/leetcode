class Solution {
public:
    typedef long long ll;
    
    int shortestSubarray(vector<int>& nums, ll k) {
        
        int n = nums.size();
      
        deque<ll> dq;
        
        vector<ll> prefix(n);
        ll sum = 0 , len = INT_MAX;
        
        for(int i=0;i<n;i++){
            
            sum += nums[i];
            
            prefix[i] = sum;
            
            if(prefix[i] >= k){
                len = min(len,(ll)i+1LL);
            }
            
            while(dq.size() && (prefix[i] - prefix[dq.front()] >= k)){  
                ll j = dq.front();
                len = min(len,i-j);
                dq.pop_front();
            }
            
            while(dq.size() && prefix[i] <= prefix[dq.back()]){  
                dq.pop_back();
            } 
                      
            dq.push_back(i);
        }
        
        if(len == INT_MAX)len = -1;
        
        return len;
    }
    
};