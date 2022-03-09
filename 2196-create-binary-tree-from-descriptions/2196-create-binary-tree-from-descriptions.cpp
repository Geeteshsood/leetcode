class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& edges) {
        
         int high = INT_MIN;
         vector<int> vis(1e5+1,false);
        
         for(auto &it : edges){
             high = max({high,it[0],it[1]});
             vis[it[1]] = true;
         }
        
         TreeNode* root;
        
         vector<int> left(high+1,-1);
         vector<int> right(high+1,-1);
        
         for(auto &i : edges){
             int u = i[0] , v = i[1] , wt = i[2];
             if(!vis[u])root = new TreeNode (u);
             
             if(wt == 1)left[u]=v;
             if(wt == 0)right[u]=v;
         }
         
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            
            int size = q.size();
            
            for(int i=0;i<size;i++){
                
                TreeNode* node = q.front();
                q.pop();
                
                if(left[node->val] != -1){
                    node->left = new TreeNode (left[node->val]);
                    q.push(node->left);
                }
                if(right[node->val] != -1){
                    node->right = new TreeNode (right[node->val]);
                    q.push(node->right);
                }
                
            }
        }
        
       return root; 
    }
};