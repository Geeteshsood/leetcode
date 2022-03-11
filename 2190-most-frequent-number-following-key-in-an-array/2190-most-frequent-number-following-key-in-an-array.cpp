class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        int n = nums.size();
        
        vector<int> cnt(1001);
        int counter = 0 , ans = -1;
        
        for(int i=0;i<n-1;i++){
            if(nums[i] == key){
                cnt[nums[i+1]]++;
                
                if(cnt[nums[i+1]] > counter){
                    counter = cnt[nums[i+1]];
                    ans = nums[i+1];
                }
            }
        }
    
        return ans;
    }
};