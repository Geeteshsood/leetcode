class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        
        vector<int> dp(26,INT_MAX);
        
        for(int i=0;i<n;i++){
            
            vector<int> freq(26);
            
            for(auto &ch : words[i]){
                freq[ch-'a']++;
            }
            
            for(int j=0;j<26;j++){
                dp[j] = min(dp[j],freq[j]);
            }
            
        }
        
        vector<string> res;
        
        for(int i=0;i<26;i++){
            
            for(int j=0;j<dp[i];j++){
                string s(1,i+'a');
                res.push_back(s);
            }
            
        }
        
      return res;  
    }
};