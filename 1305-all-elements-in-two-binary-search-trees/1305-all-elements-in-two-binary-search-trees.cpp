class Solution {
public:
    
    void find(TreeNode* root,vector<int> &res){
        
        if(root == NULL){
            return ;
        }
        
        find(root->left,res);
        res.push_back(root->val);
        find(root->right,res);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> res;
        
        find(root1,res);
        find(root2,res);

        sort(res.begin(),res.end());
        
        return res;
    }
};