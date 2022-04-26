
class Solution {
public:
    
    vector<TreeNode*> ans;
    unordered_set<int> s;

    bool find(TreeNode* root,TreeNode* par){
       
        if(root == NULL)return false;       
        
        bool x = false , y = false;
        
        if(s.find(root->val) != s.end()){
            
            x = find(root->left,root->left);
            y = find(root->right,root->right);
            
        }
        else{
            
            x = find(root->left,par);
            y = find(root->right,par);
            
            if(par == root){
              ans.push_back(root);
            }
        } 
      
        if(x)root->left = NULL;
        if(y)root->right = NULL;
        
        return s.count(root->val);
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto &x : to_delete){
            s.insert(x);
        }
        
        TreeNode* node = new TreeNode(-1);
        
        find(root,root);
       
        return ans;
    }
};