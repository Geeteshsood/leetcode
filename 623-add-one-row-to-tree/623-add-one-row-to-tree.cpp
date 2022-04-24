
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
              q.pop();
              
              if(lev == depth-1){
                  
                  TreeNode* temp1 = new TreeNode(val);
                  TreeNode* temp2 = new TreeNode(val);
                  
                  temp1->left = node->left;
                  temp2->right = node->right;
                  
                  node->left = temp1;
                  node->right = temp2;
                  
              }
              else{
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
              }
          }
            
          lev++;   
        }

        return root;
    }
};