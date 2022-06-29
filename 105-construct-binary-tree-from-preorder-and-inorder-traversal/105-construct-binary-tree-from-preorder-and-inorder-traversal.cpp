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
        int leftele = loc-instart;
        int rightele = inend - loc;
        int dest = prestart+leftele;
        
        root->left = find(instart,loc-1,in,prestart+1,dest,pre);
        root->right = find(loc+1,inend,in,dest+1,preend,pre);
        
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