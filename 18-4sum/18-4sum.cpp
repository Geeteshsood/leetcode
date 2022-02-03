class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
             sort(nums.begin(),nums.end());

             set<vector<int>> s;
        
             vector<vector<int>> ans;
        
             int n = nums.size();
        
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    
                    int x = j+1 , y = n-1;
                    
                    while(x < y){
                        
                       int left = nums[i] + nums[j];
                       int right = nums[x] + nums[y];
                       
                       if(left == target - right){
                           if(!s.count({nums[i],nums[j],nums[x]})){
                               ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                               s.insert({nums[i],nums[j],nums[x]});
                           }
                           x++;
                       }
                       else if(left < target - right)x++;
                       else y--;
                    
                    } 
                }
            }
        
        return ans;
    }
};