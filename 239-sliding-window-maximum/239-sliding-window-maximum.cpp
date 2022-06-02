class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        int n = nums.size();
        vector<int> ans;
        
        map<int,int,greater<int>> mp;
        
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        
        ans.push_back(mp.begin()->first);
        
        for(int i=k;i<n;i++){
            
            mp[nums[i]]++;
            
            if(mp[nums[i-k]] == 1){
                mp.erase(nums[i-k]);
            }
            else mp[nums[i-k]]--;
            
            ans.push_back(mp.begin()->first);
        }
       
        return ans;
    }
};