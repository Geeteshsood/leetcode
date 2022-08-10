/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
      unordered_map<int,int> mp;
    
TreeNode* find(int instart,int inend,vector<int> &in,int prestart,int preend,vector<int> &pre){
        
        if(instart > inend || prestart > preend)return NULL;
        
        int val = pre[prestart];
        
        TreeNode* root = new TreeNode(val);
        
        int idx = mp[val];
        int len = idx - instart;
        
        root->left = find(instart,idx-1,in,prestart+1,prestart + len,pre);
        root->right = find(idx+1,inend,in,prestart + len+1,preend,pre);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
         int n = pre.size();
        
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        
        TreeNode* root = find(0,n-1,in,0,n-1,pre);
        
        return root;
    }
};