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
        
        // calculating mask for each team
        
        for(int i=0;i<m;i++){
            int mask = 0;
            for(auto j:people[i]){
                mask = mask | (1<<skill[j]);
            }
            score[i] = mask;
        }
        
        int target = (1<<n)-1;
        
        vector<int> dp(1<<n,INT_MAX);
        vector<vector<int>> ans(1<<n,vector<int>());
        
        dp[0] = 0;
        
        for(int mask=0;mask<(1<<n);mask++){
            
            if(dp[mask] == INT_MAX)continue;  // means this state cannot be reached
            
            for(int j=0;j<m;j++){
                
                int nmask = mask | score[j];
                
                if(1 + dp[mask] < dp[nmask]){     // if new state can be reached
                    dp[nmask] = 1 + dp[mask];
                    ans[nmask] = ans[mask];       // then add all teams included in old state
                    ans[nmask].push_back(j);      // and new team
                }
                
            }
            
        }
        
     return ans[target];
    }
};