class Solution {
public:
    typedef long long ll;
    
    int numDecodings(string s) {

        ll mod = 1e9 + 7;
        
        ll n = s.size() , val = 0;
        vector<ll> dp(n + (ll)1);
        
        dp[0] = 1;
        
        for(ll i=1;i<=n;i++){
            
            if(s[i-1] == '*'){
                
                dp[i] = (9*dp[i-1])%mod; 
                
                if(i<2)continue;
                    
                if( s[i-2] == '1')dp[i] = (dp[i] + (9*dp[i-2])%mod)%mod;
                else if( s[i-2] == '2')dp[i] = (dp[i] + (6*dp[i-2])%mod)%mod;
                else if( s[i-2] == '*'){
                    dp[i] = (dp[i] + (15*dp[i-2])%mod)%mod;
                }
            }
            else{
                
                if(s[i-1] != '0')dp[i] = dp[i-1];
                
                if(i >=2 && s[i-2] == '*'){
                
                  int val = s[i-1]-'0';
                    
                  if(val >=0 && val <= 6) dp[i] = (dp[i] + (2*dp[i-2])%mod)%mod; // for 1->6
                  else dp[i] = (dp[i] + (1*dp[i-2])%mod)%mod;                    // for 7->9
                    
                }
                else{
                    
                     if(i>=2 && s[i-2] != '0'){ 
                         val = (s[i-1]-'0') + (s[i-2]-'0')*10;
                     
                         if(val >=1 && val <= 26){
                             dp[i] = (dp[i] + dp[i-2])%mod;
                         }
                     }   
                    
                }
            }
        }

        return dp[n]%mod;
    }
};