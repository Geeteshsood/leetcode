class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true){
            
            while(node){
                st.push(node);
                node = node->left;
            }
            
            if(st.empty())break;
            
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        
        return ans;
    }
};