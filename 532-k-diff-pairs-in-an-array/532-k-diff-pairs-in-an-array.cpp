class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        unordered_set<int> vis;
        
        for(auto &i:nums){
            mp[i]++;
        }

        int n = nums.size();
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
        
            if(vis.count(nums[i]))continue;
            
            int num1 = nums[i] + k;
            if(k == 0 && mp[num1] > 1)cnt++;
            else if(k != 0 && mp.count(num1))cnt++;
            
            vis.insert(nums[i]);
        }
        
     return cnt;
    }
};