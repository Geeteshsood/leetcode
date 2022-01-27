class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> ans;
        map<int,int,greater<>> mp;
        
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        
        auto it = mp.begin();
        
        ans.push_back(it->first);
        
        for(int i=k;i<n;i++){
            
            int val = nums[i-k];
            
            if(mp[val] == 1){
                mp.erase(val);
            }
            else mp[val]--;
            
            
            mp[nums[i]]++;
            
            auto it = mp.begin();
            ans.push_back(it->first);
        }
        
        return ans;
    }
};