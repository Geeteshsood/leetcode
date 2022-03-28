class Solution{
public:
    
    int find(int i,int cnt,vector<vector<int>> &piles,int k,vector<vector<int>> &dp){
        
        // cout<<i<<" "<<cnt<<endl;
        
        int n = piles.size();
        
        if(cnt > k)return INT_MIN;
        if(i >= n || cnt == k)return 0;
        
        if(dp[i][cnt] != -1)return dp[i][cnt];
        
        int m = piles[i].size() , ans = INT_MIN , sum = 0;
        
        for(int j=-1;j<min(m,k);j++){
            
            if(j>=0)sum += piles[i][j];
            
            int val = find(i+1,cnt+j+1,piles,k,dp);
            if(val == INT_MIN)break;
            
            ans = max(ans,sum + val);
        }
        
      return dp[i][cnt] = ans;  
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(k,-1));
        
        return find(0,0,piles,k,dp);
    }
};