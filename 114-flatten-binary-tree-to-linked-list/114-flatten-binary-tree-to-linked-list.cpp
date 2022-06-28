class Solution {
public:
    typedef pair<TreeNode*,TreeNode*> pi;
    
    pi dfs(TreeNode* root){
        
        if(root == NULL)return {NULL,NULL};
        
        pi left = dfs(root->left);
        pi right = dfs(root->right);
        
        if(!root->left && !root->right)return {root,root};
        
        
        if(left.first){
            root->right = left.first;
            root->left = NULL;
        }
        if(left.second && right.first)left.second->right = right.first;
        
        if(right.second){
            // cout<<root->val<<" "<<right.second->val<<endl;
            return {root,right.second};
        }
        // cout<<root->val<<" "<<left.second->val<<endl;
        return {root,left.second};
    }
    
//     void print(TreeNode* root){
        
//         if(root == NULL)return ;
            
//         cout<<root->val<<endl;
//         print(root->right);
        
//     }
    
    void flatten(TreeNode* root) {
        
         dfs(root);
         // cout<<"**"<<endl;
         // print(root);
    }
};