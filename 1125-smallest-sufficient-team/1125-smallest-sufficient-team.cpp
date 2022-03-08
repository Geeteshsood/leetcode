class Solution {
public:
    
    unordered_map<int,vector<int>> dp[61];
    
    vector<int> find(int i,int mask,int target,vector<int> &score){
        
        if(mask == target){
            return {-2};
        }
        else if(i == score.size()){
            return {-1};
        }
        
        if(dp[i].count(mask))return dp[i][mask];
         
        auto x = find(i+1,mask | score[i],target,score);
        auto y = find(i+1,mask,target,score);
        
        if(x[0] == -1 && y[0] == -1)return dp[i][mask] = {-1};
        else if(x[0] == -1)return dp[i][mask] = y;
        
         x.push_back(i);
        
        if(y[0] == -1)return dp[i][mask] = x;
       
        if(x.size() < y.size())return dp[i][mask] = x;
        
        return dp[i][mask] = y;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        
        unordered_map<string,int> skill;
        int n = req.size();
        
        for(int i=0;i<n;i++){
            skill[req[i]] = i;
        }
        
        int m = people.size();
        vector<int> score(m,0);
        
        for(int i=0;i<m;i++){
            int mask = 0;
            for(int j=0;j<people[i].size();j++){
                mask = mask | (1<<skill[people[i][j]]);
            }
            score[i] = mask;
        }
        
        int target = 1<<n;
        target = target-1;
        
        vector<int> v = find(0,0,target,score);

        vector<int> ans(v.begin()+1,v.end());
        
        return ans;
    }
};