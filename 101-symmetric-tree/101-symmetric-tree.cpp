class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size()){
            
          int size = q.size();
          vector<int> res;
            
          for(int i=0;i<size;i++){
              
              TreeNode* node = q.front();
              q.pop();
              
              if(node->left){
                  q.push(node->left);
                  res.push_back(node->left->val);
              }
              else res.push_back(-101);
              
              if(node->right){
                  res.push_back(node->right->val);
                  q.push(node->right);
              }
              else res.push_back(-101);
              
          }
          int n = res.size() ;
            
          if(n%2 != 0)return false;
            
          int i = 0 , j = n-1;
            
          while(i < j){
              if(res[i] != res[j])return false;
              i++,j--;
          }
            
        }
        
        return true;
    }
};