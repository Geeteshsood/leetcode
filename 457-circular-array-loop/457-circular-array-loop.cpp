class Solution {
public:
    
    int find(int i,vector<int> &nums,vector<bool> &vis){
    
        if(vis[i])return true;
        
        int n = nums.size();
        
        int idx = ((i + nums[i])%n + n)%n;
     
        if(idx == i)return false;
        else if(nums[i] > 0 && nums[idx] < 0)return false;
        else if(nums[i] < 0 && nums[idx] > 0)return false;
        
       vis[i] = true;
        
       if(find(idx,nums,vis))return true;
        
       vis[i] = false;
        
       return false;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> vis(n,false);
        
        for(int i=0;i<n;i++){
            if(find(i,nums,vis))return true;
        }
        
        return false;
    }
};