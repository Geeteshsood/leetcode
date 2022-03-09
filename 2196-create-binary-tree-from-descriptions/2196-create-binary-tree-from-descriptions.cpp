class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& edges) {
        
         unordered_map<int,int> vis,left,right;
        
         for(auto &i : edges){
             int u = i[0] , v = i[1] , wt = i[2];
             vis[v] = true;
             
             if(wt == 1)left[u]=v;
             if(wt == 0)right[u]=v;
         }
        
         TreeNode* root;
        
         for(auto &i : edges){
             int u = i[0] , v = i[1] ;
             
             if(!vis.count(u)){
                root = new TreeNode (u);
                break;
             }
             if(!vis.count(v)){
                root = new TreeNode (u);
                break;
             }
         }
         
        queue<TreeNode*> q;
        q.push(root);
        // cout<<root->val<<endl;
        while(q.size()){
            
            int size = q.size();
            
            for(int i=0;i<size;i++){
                
                TreeNode* node = q.front();
                q.pop();
                
                if(left.count(node->val)){
                    node->left = new TreeNode (left[node->val]);
                    q.push(node->left);
                }
                if(right.count(node->val)){
                    node->right = new TreeNode (right[node->val]);
                    q.push(node->right);
                }
                
            }
        }
        
       return root; 
    }
};