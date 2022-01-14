class Solution {
public:
    
    int find(int e,int f,vector<vector<int>> &dp){
        
       if(dp[e][f] != -1){
           return dp[e][f];
       }
        
       if(f == 1)return dp[e][f] = 1;
       else if(f == 0)return dp[e][f] = 0;
       else if(e == 1)return dp[e][f] = f;
        
       int ans = INT_MAX , val = 0;
        
       int start = 1 , end = f;
        
        while(start<=end){
            
            int mid = end - (end - start)/2;
            
           int down = 1 + find(e-1,mid-1,dp);
           int up = 1 + find(e,f-mid,dp);
         
           if(down < up){
               start = mid + 1;
           }
           else{
               end = mid - 1;
           }
            
           val = max(down,up);
           ans = min(ans,val);
       }
        
       return dp[e][f] = ans;
    }
    
    int superEggDrop(int e, int n) {
        
        vector<vector<int>> dp(e+1,vector<int>(n+1,-1));
        
        return find(e,n,dp);
    }
};