class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int x = 1001,y = 0;
        for(auto &i : nums){
            x = min(x,i);
            y = max(y,i);
        }
        
        return __gcd(x,y);
    }
};