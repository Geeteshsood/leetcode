
class Solution {
public:
    
    TreeNode* find(int &i,int bound,vector<int> &pre){
        
        int n = pre.size();
        
        if(i >= n || pre[i] > bound)return NULL;
        
        TreeNode* root = new TreeNode(pre[i]);
        i++;
        
        root->left = find(i,root->val,pre);
        root->right = find(i,bound,pre);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        int i=0;
        return find(i,INT_MAX,pre);
        
    }
};