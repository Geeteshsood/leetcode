
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       
        int lev = 1;
        
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size()){
            
          int size  = q.size();
            
          for(int i=0;i<size;i++){
              
              TreeNode* node = q.front();
              
              if(lev == depth-1){
                  
                  q.front()->left = new TreeNode(val , q.front()->left,NULL);
                  q.front()->right = new TreeNode(val , NULL , q.front()->right);
                  
              }
              else{
                  
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                  
              }
              
              q.pop();
          }
            
          lev++;   
        }

        return root;
    }
};