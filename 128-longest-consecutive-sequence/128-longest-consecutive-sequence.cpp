class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0)return 0;
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]] = 1;
        }
        
        int len = 1;
        
        for(auto &[key,val] : mp){
            
            if(mp.find(key-1) != mp.end()){
                mp[key] = mp[key-1] + 1;
                len = max(len,mp[key]);
            }
            
        }
        
        return len;
    }
};