class Solution {
public:
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
       
        unordered_map<int,int> mp;
        
        for(auto &num : nums){
            mp[num]++;
        }
        
        vector<int> res;
        for(auto &[num,freq] : mp){
            res.push_back(freq);
        }
        
        int n = res.size() , m = quantity.size();
        
        vector<vector<bool>> dp(n,vector<bool> (1<<m));
        vector<vector<bool>> mem(n,vector<bool> (1<<m));
        
      for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<m);mask++){
            int val = res[i];
            for(int bit=0;bit<m;bit++){
                if(mask & (1<<bit)){
                    val-=quantity[bit];
                }
            }
            
            mem[i][mask] = val>=0;
 
            if(i==0){
                dp[i][mask] = mem[i][mask];
            }
        }
        if(mem[i][(1<<m)-1])return true;
      }

        for(int i=1;i<n;i++){
            for(int mask=0;mask<(1<<m);mask++){
                dp[i][mask] = mem[i][mask];
                for(int submask=mask;submask;submask = (submask-1) & mask){
                    
                    int nmask = submask^mask;
                    
                    if(nmask)dp[i][mask] = dp[i][mask] | (mem[i][nmask] && dp[i-1][submask]);
                    else dp[i][mask] = dp[i][mask] | dp[i-1][submask];

                }
            }
            if(dp[i][(1<<m)-1])return true;
        }
        
       return false;
    }
};