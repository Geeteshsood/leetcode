class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        int n = words.size() , m = puzzles.size();
        
        unordered_map<int,int> word;
        
        for(int i=0;i<n;i++){
            int mask = 0;
            for(auto &ch : words[i]){
                mask = mask | (1<<(ch-'a'));
            }
            word[mask]++;
        }
        
        unordered_map<int,int> dp[26];
        
        for(auto &[mask,y] : word){
            for(int i=0;i<26;i++){
                if(mask & (1<<i)){
                    dp[i][mask] = y;
                }
            }
        }
        
        vector<int> ans(m);

        for(int i=0;i<m;i++){
            
            int pmask = 0;
            
            for(auto &ch : puzzles[i]){
                pmask = pmask | (1<<(ch-'a'));
            }
            
            int cnt = 0;
            
            for(auto &[wmask,freq] : dp[puzzles[i][0]-'a']){
                
                bool flag1 = (pmask == (pmask | wmask));
                bool flag2 = wmask & (1<<(puzzles[i][0]-'a'));
                
                if(flag1 && flag2){
                    cnt += freq;
                }
            }
            
            ans[i] = cnt;
        }
       
        return ans;
    }
};