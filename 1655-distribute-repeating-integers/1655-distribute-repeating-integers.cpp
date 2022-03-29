class Solution {
public:
    
    // 1 1 1 1 1 1 2 1 1 1 2 7 6 2 1 7 1 19 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1
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
            bool flag = false;
            for(int bit=0;bit<m;bit++){
                if(mask & (1<<bit)){
                    val-=quantity[bit];
                    flag = true;
                }
            }
            
            mem[i][mask] = val>=0 && flag;
            // if(mem[i][mask]){
            //     bitset<2> b(mask);
            //     cout<<i<<" "<<b<<endl;
            // }
            if(i==0){
                dp[i][mask] = mem[i][mask];
            }
        }
        if(mem[i][(1<<m)-1])return true;
      }
        
        // cout<<" up"<<endl;
        // for(auto &i : res)cout<<i<<" ";
        // cout<<endl;
        for(int i=1;i<n;i++){
            cout<<i<<endl;
            for(int mask=0;mask<(1<<m);mask++){
                dp[i][mask] = mem[i][mask];
                for(int submask=mask;submask;submask = (submask-1) & mask){
                    
                    int nmask = submask^mask;
                    
                    if(nmask)dp[i][mask] = dp[i][mask] | (mem[i][submask^mask] && dp[i-1][submask]);
                    else dp[i][mask] = dp[i][mask] | dp[i-1][submask];
                    
                // if(i == n-1 && mask == ((1<<m)-1)){
//                     bitset<2>b1(mask);
//                     bitset<2>b2(nmask);
//                     bitset<2>b3(submask);
                    
//                     cout<<b1<<" "<<b2<<" "<<mem[i][nmask]<<" "<<b3<<" "<<dp[i-1][submask]<<endl;
                }
                // }
            }
            if(dp[i][(1<<m)-1])return true;
        }
        
       return false;
    }
};