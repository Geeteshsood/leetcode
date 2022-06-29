class Solution {
public:
        
    unordered_map<int,int> mp;
    
    TreeNode* find(int instart,int inend,vector<int> &in,int prestart,int preend,vector<int> &pre){
        
        if(instart > inend || prestart > preend)return NULL;
        
        TreeNode* root = new TreeNode(pre[prestart]);
        
        if(preend == prestart){
            return root;
        }
        
        int loc = mp[root->val];
        int ele = loc-instart;
        
        root->left = find(instart,loc-1,in,prestart+1,prestart + ele,pre);
        root->right = find(loc+1,inend,in,prestart+ele+1,preend,pre);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int n = in.size();
        
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        
        return find(0,n-1,in,0,n-1,pre);
    }
};