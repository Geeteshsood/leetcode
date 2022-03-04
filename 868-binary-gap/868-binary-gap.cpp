class Solution {
public:
    int binaryGap(int n) {

        int prev = INT_MAX , diff = 0 , ans = INT_MIN;
        
        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                diff = i-prev;
                prev = i;
                ans = max(ans,diff);
            }
        }
     
    return max(ans,0);
    }
};