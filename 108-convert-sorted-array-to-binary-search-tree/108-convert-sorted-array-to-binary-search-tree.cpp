class Solution {
public:
    
    TreeNode* dfs(int st,int end,vector<int> &nums){
        
        if(st > end)return NULL;
        
        int mid = st + (end - st)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = dfs(st,mid-1,nums);
        root->right = dfs(mid+1,end,nums);
       
     return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();
        return dfs(0,n-1,nums);
    }
};