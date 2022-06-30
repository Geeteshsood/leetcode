class Solution {
public:
    
    int idx = 0;
    
    TreeNode* find(int ub,vector<int> &pre){
        
        int n = pre.size();
        
        TreeNode* root = new TreeNode(pre[idx]);
        idx++;
        
        if(idx < n && pre[idx] < root->val){
            root->left = find(root->val,pre);
        }
        
        if(idx < n && pre[idx] < ub){
            root->right = find(ub,pre);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        return find(INT_MAX,pre);
    }
};