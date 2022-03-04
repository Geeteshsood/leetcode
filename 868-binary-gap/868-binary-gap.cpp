class Solution {
public:
    int binaryGap(int n) {

        int prev = INT_MAX , diff = 0 , ans = 0;
        
        for(int i=0;i<32 && n;i++){
            if(n & 1){
                diff = i-prev;
                prev = i;
                ans = max(ans,diff);
            }
            n = n>>1;
        }
     
    return ans;
    }
};