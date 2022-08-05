class Solution {
public:
    
    int find(int e,int f,vector<vector<int>> &dp){
        
        if(e == 1)return f;
        else if(e ==0 || f == 0)return 0;
        else if(f == 1)return 1;
    
        if(dp[e][f] != -1)return dp[e][f];
        
        int ans = INT_MAX;
        int start = 1 , end = f;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            int down = 1 + find(e-1,mid-1,dp);
            int up = 1 + find(e,f-mid,dp);
            
            int val =  max(up,down);
            
            if(down < up){
                start = mid+1;
            }
            else end = mid-1;
            
            ans = min(val,ans);
        }
        
        return dp[e][f] = ans;
        
    }
    
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        
       return find(k,n,dp) ;
        
    }
};