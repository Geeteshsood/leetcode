class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true){
            
            while(node){
                st.push(node);
                node = node->left;
            }
            
            if(st.empty())break;
            
            TreeNode* temp = st.top();
            st.pop();
            inorder.push_back(temp->val);
            
            node = temp;
            node = node->right;
            
        }
        
    return inorder;
    }
};