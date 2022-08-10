class Solution {
public:
    
    unordered_map<int,int> mp;
    
TreeNode* find(int instart,int inend,vector<int> &in,int posstart,int posend,vector<int> &post){
        
        if(instart > inend || posstart > posend)return NULL;
        
        int val = post[posend];
        
        TreeNode* root = new TreeNode(val);
        
        int idx = mp[val];
        int len = idx - instart-1;
        
        root->left = find(instart,idx-1,in,posstart,posstart + len,post);
        root->right = find(idx+1,inend,in,posstart + len+1,posend-1,post);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int n = post.size();
        
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        
        TreeNode* root = find(0,n-1,in,0,n-1,post);
        
        return root;
    }
};