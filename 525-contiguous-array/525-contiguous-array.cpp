class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size() , ans = 0 , sum = 0;
        
        unordered_map<int,int> mp;
        
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            
            if(nums[i] == 1)sum++;
            else sum--;
            
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
            else ans = max(ans,i-mp[sum]);
        }
      
        return ans;
    }
};