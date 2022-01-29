class Solution {
public:
    
	 int find(int i,string &s,vector<int> &dp){
        
        if(i == s.size())return 1;
        
        int sum = 0 , val = 0;
        
        if(dp[i] != -1)return dp[i];
        
        for(int j=i;j<s.size();j++){
            
            val = val*10 + s[j]-'0';
            
            if(val < 1 || val > 26)break;
                
            sum += find(j + 1,s,dp);
        }
        
      return dp[i] = sum;  
    }
    
    int numDecodings(string s) {
        
         vector<int> dp(s.size(),-1);
		   
		 return find(0,s,dp);
    }
};