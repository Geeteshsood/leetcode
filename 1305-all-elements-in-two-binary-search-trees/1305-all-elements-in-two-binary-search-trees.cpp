class Solution {
public:
    
    void push_left(TreeNode* root,stack<TreeNode*> &st){
        
        if(root == NULL)return ;
        
        st.push(root);
        push_left(root->left,st);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ans;
        
        stack<TreeNode*> st1,st2;
        
        push_left(root1,st1);
        push_left(root2,st2);
        
        TreeNode *node = NULL;
        
        while(st1.size() || st2.size()){
            
           if( !st1.empty() && (st2.empty() || st1.top()->val < st2.top()->val)){
               node = st1.top();
               st1.pop();
               
               ans.push_back(node->val);
               node = node->right;
               
               push_left(node,st1);
           }
           else if(!st2.empty() && (st1.empty() || st2.top()->val <= st1.top()->val)){
               node = st2.top();
               st2.pop();
               
               ans.push_back(node->val);
               node = node->right;
               
               push_left(node,st2);
           }
        }
      
        return ans;
    }
};