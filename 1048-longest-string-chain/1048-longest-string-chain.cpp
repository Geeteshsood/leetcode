class Solution {
public:

    bool check(int i,int j,vector<string> &words){
    
        string s1 = words[i];
        string s2 = words[j];
        
        int m = s1.size() , n = s2.size();
        
        if(s1[0] != s2[0]){
            return s1.substr(0) == s2.substr(1);
        }
    
        if(s1[m-1] != s2[n-1]){
            return s1.substr(0,m) == s2.substr(0,n-1);
        }
        
        int x=0,y=0;
        
        while(x < m && y < n){
            if(s1[x] == s2[y]){
                x++;
                y++;
            }
            else break;
        }
        
        y++;
        
        while(x < m && y < n){
            if(s1[x] == s2[y]){
                x++;
                y++;
            }
            else break;
        }
        
        return x == m && y == n;
    }
    
    int dfs(int i,vector<int> &dp,vector<vector<int>> &adj){
        
        if(dp[i] != -1)return dp[i];
        
        int ans = 0;
        
        for(auto &it : adj[i]){
            
            int val = dfs(it,dp,adj);
            
            ans = max(ans,val);
            
        }
        
       return dp[i] = 1 + ans; 
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        unordered_map<int,vector<int>> mp;
        
        int n = words.size();
        vector<vector<int>> adj(n,vector<int>());
        
        for(int i=0;i<n;i++){
            mp[words[i].size()].push_back(i);
        }
        
        for(int i=1;i<16;i++){
            
            // cout<<i<<" "<<mp[i].size()<<" "<<mp[i+1].size()<<endl;
            
            if(mp[i].size() == 0 || mp[i+1].size() == 0)continue;
            
            for(auto &x : mp[i]){
                for(auto &y : mp[i+1]){
                    if(check(x,y,words)){
                         // cout<<i<<" "<<x<<" && "<<y<<endl;
                         adj[x].push_back(y);
                    }
                }
            }
            
        }
        
        vector<int> dp(n,-1);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int val = dfs(i,dp,adj);
            ans = max(ans,val);
        }
     
        return ans;
    }
};