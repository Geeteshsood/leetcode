class Solution {
public:
    
    unordered_map<TreeNode*,int> mp[2];
    
    int find(TreeNode* root,bool flag){
        
        if(root == NULL)return 0;
        
        if(mp[flag].find(root) != mp[flag].end())return mp[flag][root];
        
        int left1 = find(root->left , !flag);
        int right1 = find(root->right, !flag);
        
        int val1 = left1 + right1;
        if(flag)val1 += root->val;
        
        int left2 = find(root->left , flag);
        int right2 = find(root->right, flag);
        
        int val2 = left2 + right2;
        
        
        return mp[flag][root] = max(val1,val2);
    }
    
    int rob(TreeNode* root) {
        
        return find(root,true);
        
    }
};