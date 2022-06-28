class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root->left && !root->right)return true;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        if(root->left)q1.push(root->left);
        if(root->right)q2.push(root->right);
        
        if(q1.size() != q2.size() || q1.front()->val != q2.front()->val)return false;
        
        while(q1.size() && q2.size()){
            
             TreeNode* node1 = q1.front();
             TreeNode* node2 = q2.front();
            
             q1.pop(),q2.pop();
            
             if(!node1 && !node2)continue;
             else if(!node1 || !node2)return false;
            
             // cout<<node1->val<<" "<<node2->val<<endl;
             if(node1->val != node2->val)return false;
                 
             q1.push(node1->left);
             q1.push(node1->right);
            
             q2.push(node2->right);
             q2.push(node2->left);
                 
        }
        
        return true;
    }
};