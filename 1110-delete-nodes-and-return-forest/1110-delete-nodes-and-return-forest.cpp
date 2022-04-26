
class Solution {
public:
    
    bool find(TreeNode* root,TreeNode* par,vector<TreeNode*> &ans,unordered_set<int> &s){
       
        if(root == NULL)return false;       
        
        bool x = false , y = false;
        
        if(s.find(root->val) != s.end()){
            
            x = find(root->left,root->left,ans,s);
            y = find(root->right,root->right,ans,s);
            
        }
        else{
            
            x = find(root->left,par,ans,s);
            y = find(root->right,par,ans,s);
            
            if(par == root){
              ans.push_back(root);
            }
        } 
      
        if(x)root->left = NULL;
        if(y)root->right = NULL;
        
        return s.count(root->val);
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> ans;
        unordered_set<int> s;
        
        for(auto &x : to_delete){
            s.insert(x);
        }
        
        TreeNode* node = new TreeNode(-1);
        
        find(root,root,ans,s);
       
        return ans;
    }
};