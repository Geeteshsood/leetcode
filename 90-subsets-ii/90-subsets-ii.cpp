class Solution {
public:
    
    void find(int i,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans){
        
        int n = nums.size();
        
        if(i == n){
            ans.push_back(temp);
            return ;
        }
        
        int j = i;
        while(j<n-1 && nums[j] == nums[j+1])j++;
        
        find(j+1,nums,temp,ans);
        
        temp.push_back(nums[i]);
        
        find(i+1,nums,temp,ans);
        
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
         sort(nums.begin(),nums.end());
        
         vector<vector<int>> ans;
         vector<int> temp;
        
         find(0,nums,temp,ans);
        
        return ans;
    }
};