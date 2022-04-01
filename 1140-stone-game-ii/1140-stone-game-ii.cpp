class Solution {
public:
    
    typedef pair<int,int> pi;
    pi dp[101][65][2];
    
    pi find(int i,int M,vector<int> &piles,bool player1){
        
        int stone = 0 , maxi = 0 , sec = 0 , n = piles.size();
        
        if(i >= n)return {0,0};
        
        if(dp[i][M][player1].first != -1)return dp[i][M][player1];
            
        for(int X=1;X<=2*M && i+X-1<n;X++){
            
            stone += piles[i+X-1];
            
            auto it = find(i+X,max(M,X),piles,!player1);
            
            if(player1 && stone + it.first > maxi){
                maxi = stone + it.first;
                sec = it.second;
            }
            else if(!player1 && stone + it.second > sec){
                sec = stone + it.second;
                maxi = it.first;
            }
        }
      
        return dp[i][M][player1] = {maxi,sec};
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        
        pi it = find(0,1,piles,true);
        
        return it.first;
    }
};