class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        
        int n = nums.size();
        
        int Xor = 0;
        
        if(n%4 == 0)Xor = n;
        else if(n%4 == 1)Xor = 1;
        else if(n%4 == 2)Xor = n+1;
        else Xor = 0;
          
        for(int i=0;i<n;i++){
            Xor = Xor^nums[i];
        }
          
        return Xor;
    }
};