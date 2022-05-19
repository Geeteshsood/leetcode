class Solution {
public:
    
    typedef long long ll;
    
    bool isVowel(char ch){
        
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return true;
        
        return false;
    }
    
    long long countVowels(string word) {
        
       ll n = word.size();
        
       vector<ll> dp(n);
       ll sum = 0;
        
       if(isVowel(word[0]))dp[0] = 1,sum = 1;
        
       for(ll i=1;i<n;i++){
           
           if(isVowel(word[i])){
               dp[i] = dp[i-1] + i+1;
           }
           else{
               dp[i] = dp[i-1];
           }
           
           sum += dp[i];
       }
    
        return sum;
    }
};