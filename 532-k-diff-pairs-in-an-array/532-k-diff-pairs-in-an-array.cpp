class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        set<pair<int,int>> s;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[j]-nums[i]) == k){
                    int mini = min(nums[i],nums[j]);
                    int maxi = max(nums[i],nums[j]);
                    
                    if(!s.count({mini,maxi})){
                        s.insert({mini,maxi});
                    }
                }
            }
        }
        
        
     return s.size();
    }
};