class Solution {
public:

    stack<TreeNode*> nex,bef;
    
    int pushleft(TreeNode* node){
        
        while(node){
           nex.push(node);
           node = node->left;
        }
        
        if(nex.empty())return NULL;
        
        return nex.top()->val;
    }
    
     int pushright(TreeNode* node){
        
        while(node){
           bef.push(node);
           node = node->right;
        }
         
        if(bef.empty())return NULL;
         
        return bef.top()->val;
    }
    
    int next() {
            
        TreeNode* node = nex.top();
        nex.pop();
        
        pushleft(node->right);
        
        return node->val;
    }
    
    int before() {
            
        TreeNode* node = bef.top();
        bef.pop();
        
        pushright(node->left);
        
        return node->val;
    }
    
    bool findTarget(TreeNode* root, int k) {
       
        int left = pushleft(root);
        int right = pushright(root);
        
        while(left < right){
            
           // cout<<left<<" "<<right<<endl;
            
          int sum = left + right;
          
          if(sum == k)return true;
          else if(sum > k)right = before();
          else left = next();
            
        }
        
        return false;
    }
};