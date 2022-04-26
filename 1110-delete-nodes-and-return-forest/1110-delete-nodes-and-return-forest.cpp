
class Solution {
public:
    
    vector<TreeNode*> ans;
    unordered_set<int> s;
    unordered_map<TreeNode*,TreeNode*> mp;
    
    void dfs(TreeNode* root , TreeNode* par){
        
       if(root == NULL)return ;
        
       dfs(root->left ,root);
       dfs(root->right,root);
        
       mp[root] = par;
    }
    
    void find(TreeNode* root,TreeNode* par,bool isLeft){
       
        if(root == NULL)return ;       
        
        if(s.find(root->val) != s.end()){
            
            if(mp[root]->val != -1){
                if(isLeft)mp[root]->left = NULL;
                else mp[root]->right = NULL;
            }
            
            find(root->left,root->left,true);
            find(root->right,root->right,false);
            
        }
        else {
            
            find(root->left,par,true);
            find(root->right,par,false);
            
            if(par == root){
              ans.push_back(root);
            }
        } 
         
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto &x : to_delete){
            s.insert(x);
        }
        
        TreeNode* node = new TreeNode(-1);
        
        dfs(root,node);
        find(root,root,false);
       
        return ans;
    }
};