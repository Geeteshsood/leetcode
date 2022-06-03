class Solution {
public:
    
     int dp[21][5001];
    
    int find(int i,int sum1,int sum2,vector<int> &rods){
        
        int n = rods.size();
        
        // cout<<i<<" "<<sum1<<" "<<sum2<<endl;
        
        if(i == n){
            if(sum1 == sum2)return sum1;
            else return -2;
        }

        if(dp[i][abs(sum1-sum2)] != -1){
            
            if(dp[i][abs(sum1-sum2)] == -2)return -2;
            
            return max(sum1,sum2) + dp[i][abs(sum1-sum2)];
        }
        
        int x = find(i+1,sum1 + rods[i],sum2,rods);
        int y = find(i+1,sum1,sum2 + rods[i],rods);
        int z = find(i+1,sum1,sum2,rods);
        
        int val = max({x,y,z});

        if(val == -2)return dp[i][abs(sum1-sum2)] = val; 
            
        dp[i][abs(sum1-sum2)] = val - max(sum1,sum2);
        
        return val;
    }
    
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,0,rods);
    }
};