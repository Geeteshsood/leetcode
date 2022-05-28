class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<vector<bool>> dp(n,vector<bool>(2,false));
        
        bool odd = true , even = false;
        map<int,int> mp;
        
        mp[arr[n-1]] = n-1;
        
        dp[n-1][odd] = true , dp[n-1][even] = true;
        
        for(int i=n-2;i>=0;i--){
        
            auto it = mp.lower_bound(arr[i]);
            
            if(it != mp.end()){
                // cout<<i<<" * "<<arr[i]<<" -> "<<it->first<<endl;
                dp[i][odd] = dp[it->second][even];
            }
            else it--;
                
            if(arr[i] < it->first)it--;
            
            // cout<<i<<" "<<arr[i]<<" -> "<<it->first<<endl;
            if(arr[i] >= it->first)dp[i][even] = dp[it->second][odd];
            
            mp[arr[i]] = i;
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            // cout<<i<<" -> "<<dp[i][odd]<<" "<<dp[i][even]<<endl;
            if(dp[i][odd])cnt++;
        }
        
        return cnt;
    }
};