class Solution {
public:
    typedef pair<int,int> pi;
    
    int uniqueLetterString(string s) {
        
        int n = s.size();
        vector<pi> pos(26,{-1,-1});
        
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            
            int j = pos[s[i]-'A'].first , k = pos[s[i]-'A'].second;
            
            if(i!=0){
                dp[i] = dp[i-1] + (i-j)-(j-k);
            }
            else dp[i] = 1;
            
            pos[s[i]-'A'].second = pos[s[i]-'A'].first;
            pos[s[i]-'A'].first = i;
            
        }

        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += dp[i];
        }
        
        return sum;
    }
};