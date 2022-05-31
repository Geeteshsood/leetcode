class Solution {
public:
    
    int next(int i,vector<int> &nums){
        
        int n = nums.size();
        
        return ((i + nums[i])%n + n)%n;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            int slow = i , fast = i;
            
        while(nums[slow]*nums[next(fast,nums)] > 0 && nums[fast]*nums[next(next(fast,nums),nums)] > 0){
                
                slow = next(slow,nums);
                fast = next(next(fast,nums),nums);
                
                if(slow == fast){
                    if(abs(nums[slow])%n != 0)return true;  // cycle length == 1
                    else break;
                }
                
            }
            
            int j = next(i,nums);
            nums[i] = 0;
            
            while(nums[j]*nums[i] > 0){
                nums[j] = 0;
                i = j;
                j = next(j,nums);
            }
            
        }
        
        return false;
    }
};