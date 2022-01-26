class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ans;
        
        TreeNode* root = NULL;
        
        root = root1;
        
        stack<TreeNode*> st1,st2;
        
        while(root){
            st1.push(root);
            root = root->left;
        }
        
        root = root2;
        
        while(root){
            st2.push(root);
            root = root->left;
        }
        
        TreeNode *node = NULL;
        
        while(true){
           if(st1.empty() && st2.empty())break;
          
            
           if( !st1.empty() && (st2.empty() || st1.top()->val < st2.top()->val)){
               node = st1.top();
               st1.pop();
               ans.push_back(node->val);
               node = node->right;
               
               while(node){
                   st1.push(node);
                   node = node->left;
               }
           }
           else if(!st2.empty() && (st1.empty() || st2.top()->val <= st1.top()->val)){
               node = st2.top();
               st2.pop();
               ans.push_back(node->val);
               node = node->right;
               
               while(node){
                   st2.push(node);
                   node = node->left;
               }
           }
        }
      
        return ans;
    }
};