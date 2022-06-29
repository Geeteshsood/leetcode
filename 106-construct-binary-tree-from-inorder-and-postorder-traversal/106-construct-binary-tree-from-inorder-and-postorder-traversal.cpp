class Solution {
public:
    
        unordered_map<int,int> mp;
    
    TreeNode* find(int instart,int inend,vector<int> &in,int poststart,int postend,vector<int> &post){
        
        if(instart > inend || poststart > postend)return NULL;
        
        TreeNode* root = new TreeNode(post[postend]);
        
        if(postend == poststart){
            return root;
        }
        
        int loc = mp[root->val];
        int ele = loc-instart;
        
        root->left = find(instart,loc-1,in,poststart,poststart + ele-1,post);
        root->right = find(loc+1,inend,in,poststart+ele,postend-1,post);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int n = in.size();
        
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        
        return find(0,n-1,in,0,n-1,post);
        
    }
};