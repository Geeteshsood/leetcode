class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        int dp[13][numArrows+1];
        
        for(int i=0;i<=aliceArrows.size();i++){
            for(int j=0;j<=numArrows;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(j>aliceArrows[i-1]){
                    dp[i][j]=max(dp[i-1][j], dp[i-1][j-aliceArrows[i-1]-1]+i-1);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        // for(int i=0;i<=aliceArrows.size();i++){
        //     for(int j=0;j<=numArrows;j++){
        //         cout<<dp[i][j]<<" ";        
        //     }
        //     cout<<endl;
        // }
       
        vector<int> res;
        
        int i=12;
        int j=numArrows;
        
        while(i>0 && j>0){
            
            if(dp[i-1][j]==dp[i][j]){
                res.push_back(0);
                i--;
            }
            else{
                res.push_back(aliceArrows[i-1]+1);
                j-=(aliceArrows[i-1]+1);
                i--;
            }
        }
        
        while(i>0){
            res.push_back(0);
            i--;
        }
        
        int cnt=0;
        reverse(res.begin(), res.end());
        
        for(int m=0;m<res.size();m++){
            cnt+=res[m];
        }
        res[0]+=(numArrows-cnt);
        return res;
        
    }
};