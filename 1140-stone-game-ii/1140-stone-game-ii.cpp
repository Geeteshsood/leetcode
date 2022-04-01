class Solution {
public:
    
    int dp[101][65];
    
    int find(int i,int M,vector<int> &piles,vector<int> &score){
        
        // cout<<i<<endl;
        
        int n = piles.size();
        
        if(i >= n)return 0;
        
        if(dp[i][M] != -1)return dp[i][M];
        
        int ans = 0;
        
        for(int X=1;X<=2*M && i+X<=n;X++){  // p1 choice
            
              int sum = score[i+X] - score[i];
            
              int m = max(M,X) , val = INT_MAX;
            
              for(int j=1;j<=2*m;j++){    // p2 choice
                  
                 int x = find(i+j+X,max(m,j),piles,score);
                 
                 val = min(val,sum + x);
              }
            
             // cout<<i<<" "<<sum<<" "<<val<<endl;
            ans = max(ans,val);
        }
      
        return dp[i][M] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        
        memset(dp,-1,sizeof(dp));
        
        int n = piles.size();
        vector<int> score(n+1);
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += piles[i];
            score[i+1] = sum;
        }

        return find(0,1,piles,score);
    }
};