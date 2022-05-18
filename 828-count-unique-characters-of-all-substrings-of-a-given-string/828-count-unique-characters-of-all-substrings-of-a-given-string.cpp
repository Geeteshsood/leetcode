class Solution {
public:
    int uniqueLetterString(string s) {
        
        int n = s.size() , sum = 0;
        
        int pos[26][2];
        memset(pos,-1,sizeof(pos));
        
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            
            int j = pos[s[i]-'A'][0] , k = pos[s[i]-'A'][1];
            
            if(i!=0){
                dp[i] = dp[i-1] + (i-j)-(j-k);
            }
            else dp[i] = 1;
            
            pos[s[i]-'A'][1] = pos[s[i]-'A'][0];
            pos[s[i]-'A'][0] = i;
            
            sum += dp[i];
        }

        return sum;
    }
};