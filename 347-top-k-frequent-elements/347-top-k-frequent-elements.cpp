class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<vector<int>> bucket(n+1);
        unordered_map<int,int> mp;
        
        for(auto &it : nums){
            mp[it]++;
        }
        
        for(auto &[key,value] : mp){
            bucket[value].push_back(key);
        }
        
        vector<int> res;
        
        for(int i=n;i>0;i--){
          for(auto &it : bucket[i]){
              res.push_back(it);
              if(res.size() == k)return res;
          }
        }
        
        return res;
    }
};