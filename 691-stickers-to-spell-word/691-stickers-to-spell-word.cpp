class Solution {
public:
    
    int find(unordered_map<string,int> &mp,vector<vector<int>> &dp,string target){
        
        if(target.size() == 0)return 0;
          
        if(mp.count(target))return mp[target];
        
        int n = dp.size();
        
        vector<int> tar(26);
        
        for(auto &ch : target){
             tar[ch-'a']++;
        }
        
        int val = INT_MAX;
        
        for(int i=0;i<n;i++){
           
          if(dp[i][target[0]-'a'] == 0)continue;
            
          string s;
            
           for(int k=0;k<26;k++){
               
               if(tar[k]-dp[i][k] > 0){
                   s += string(tar[k]-dp[i][k],k+'a');
               }
           }
             
           val = min(val , find(mp,dp,s)); 
       }
      
        if(val == INT_MAX)return mp[target] = val;
        
        return mp[target] = 1 + val;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        
        int n = stickers.size();

        vector<vector<int>> dp(n,vector<int>(26));
        
        for(int i=0;i<n;i++){
            for(auto &ch : stickers[i]){
                dp[i][ch-'a']++;
            }
        }
        
        unordered_map<string,int> mp;
        
        int x = find(mp,dp,target);
         
        if(x == INT_MAX)return -1;
         
        return x;
    }
};