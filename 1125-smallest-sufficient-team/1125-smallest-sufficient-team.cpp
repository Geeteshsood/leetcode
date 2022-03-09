class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        
        unordered_map<string,int> skill;
        int n = req.size();
        
        for(int i=0;i<n;i++){
            skill[req[i]] = i;
        }
        
        int m = people.size();
        vector<int> score(m,0);
        
        int target = (1<<n)-1;
        
        vector<int> dp(1<<n,INT_MAX);
        vector<vector<int>> ans(1<<n,vector<int>());
        dp[0] = 0;
        
        for(int i=0;i<m;i++){
            int mask = 0;
            for(int j=0;j<people[i].size();j++){
                mask = mask | (1<<skill[people[i][j]]);
            }
            score[i] = mask;
            
            for(int mask=0;mask<(1<<n);mask++){
            
                if(dp[mask] == INT_MAX)continue;
            
                int nmask = mask | score[i];
                
                if(1 + dp[mask] < dp[nmask]){
                    dp[nmask] = 1 + dp[mask];
                    ans[nmask] = ans[mask];
                    ans[nmask].push_back(i);
                }
                
            }
        }
        
     // cout<<dp[target];
        
     return ans[target];
    }
};