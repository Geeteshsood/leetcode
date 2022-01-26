class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)return 0;
        
        int jump = 1, maxReach = nums[0] , curReach = nums[0];
        
        for(int i=1;i<n-1;i++){
            
            maxReach = max(maxReach , i + nums[i]);
            
            if(i == curReach){
                jump++;
                curReach = maxReach;
            }
        }
        
        return jump;
    }
};