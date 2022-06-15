class Solution {
public:
    
    static bool cmp(string &s1,string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        
        unordered_map<string,int> dp;
        int ans = 0;
        
        for(auto &word : words){
            
            for(int i=0;i<word.size();i++){
               string s = word.substr(0,i) + word.substr(i+1);
               
                if(dp.find(s) == dp.end())dp[word] = max(dp[word],1);
                else dp[word] = max(dp[word] , 1 + dp[s]);
            }
            
            ans = max(ans,dp[word]);
        }
        
        return ans;
    }
};