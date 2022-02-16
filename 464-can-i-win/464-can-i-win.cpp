class Solution {
public:
    
    bool find(int val,int digit,int mask,int n,int k,vector<int> &dp){
        
        if(val >= k){
            return false;
        }
        
        mask |= (1<<digit);
        
        if(dp[mask] != -1)return dp[mask];
        
        for(int i=1;i<=n;i++){
            
            if(!(mask & (1<<i))){
                
                bool flag = find(val+i,i,mask,n,k,dp);
  
                if(!flag){
                    dp[mask] = true;
                    mask = mask^(1<<digit);
                    return true;
                }
            }
            
        }
        
        dp[mask] = false;
        
        mask = mask^(1<<digit);
        
        return false;
    }
    
    bool canIWin(int n, int k) {
        
        int size = 1<<(n+1);
        
        vector<int> dp(size,-1);
        
        int maxReach = (n*(n+1))/2;
        
        if(maxReach < k)return false;
        
        if(k == 0)return true;
        
        return find(0,0,0,n,k,dp);
        
    }
};