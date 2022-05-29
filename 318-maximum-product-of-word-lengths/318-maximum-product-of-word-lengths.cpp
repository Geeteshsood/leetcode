class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            int mask = 0;
            for(int j=0;j<words[i].size();j++){
                mask = mask | (1<<(words[i][j]-'a'));
            }
            dp[i] = mask;
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((dp[i] & dp[j]) == 0){
                    int x = words[i].size() , y = words[j].size();
                    
                    ans = max(ans,x*y);
                }
            }
        }
        
        return ans;
    }
};