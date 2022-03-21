class Solution {
public:
    vector<int> maximumBobPoints(int n, vector<int>& al) {
       
        int m = al.size();
        int amask = 0 , maxi = INT_MIN;
        
        for(int mask=0;mask<(1<<m);mask++){
            
            int arruse = 0 , score = 0;
            
            for(int i=0;i<12;i++){
                if(mask & (1<<i)){
                    arruse += (al[i]+1);
                    score += i;
                }
            }
            
            if(arruse <= n && score > maxi){
                maxi = score;
                amask = mask;
            }
            
        }
        
        vector<int> ans(m);
        int sum = 0;
        
        for(int i=0;i<12;i++){
            if(amask & (1<<i)){
                ans[i] = al[i]+1;
                sum += ans[i];
            }
        }
        
        ans[0] = n - sum;
        
        return ans;
    }
};