class Solution {
public:
    
    bool isSame(TreeNode* p, TreeNode* q){
        
        if(!p && !q)return true;
        else if((p && !q) || (!p && q))return false;
    
        if(p->val != q->val)return false;
        
        bool left = isSame(p->left,q->left);
        bool right = isSame(p->right,q->right);   
        
        return left && right;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isSame(p,q);
    }
};