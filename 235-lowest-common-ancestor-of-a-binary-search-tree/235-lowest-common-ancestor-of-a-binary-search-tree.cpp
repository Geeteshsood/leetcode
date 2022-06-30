class Solution {
public:
    
    TreeNode* find(TreeNode* root,TreeNode* p,TreeNode* q){
        
        int data = root->val;
        
        if(data > p->val && data > q->val){
            return find(root->left,p,q);
        }
        
        if(data < p->val && data < q->val){
            return find(root->right,p,q);
        }
        
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
           return find(root,p,q);
    }
};