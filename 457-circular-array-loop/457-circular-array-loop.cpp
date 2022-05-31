class Solution {
public:
    
    int find(int i,vector<int> &nums,vector<bool> &vis){
    
        int n = nums.size();
        
        int idx = ((i + nums[i])%n + n)%n;
     
        if(idx == i)return false;
        else if(nums[i] > 0 && nums[idx] < 0)return false;
        else if(nums[i] < 0 && nums[idx] > 0)return false;
        
        if(vis[i])return true;
        else vis[i] = true;
        
        return find(idx,nums,vis);
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> vis(n,false);
        
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            if(find(i,nums,vis))return true;
        }
        
        return false;
    }
};