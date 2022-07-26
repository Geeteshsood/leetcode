class Codec {
public:

    string serialize(TreeNode* root) {
        
        if(root == NULL)return "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        string str = to_string(root->val) + ",";
        
        while(q.size()){
            
            int size = q.size();
            
            for(int g=0;g<size;g++){
                
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                    str += to_string(node->left->val) + ",";
                }
                else str += "#,";
                    
                if(node->right){
                    q.push(node->right);
                    str += to_string(node->right->val) + ",";
                }
                else str += "#,";
            }
            
        }

        return str;
    }

    TreeNode* deserialize(string data) {
        
       if(data.size() == 0)return NULL;
        
       stringstream str(data);
       string s;
        
       getline(str,s,',');
        
       TreeNode* root = new TreeNode(stoi(s));
        
       queue<TreeNode*> q;
       q.push(root);
        
       while(q.size()){
           
         int size = q.size();
           
         for(int g=0;g<size;g++){
             
              TreeNode* node = q.front();
              q.pop();
             
              getline(str,s,',');
             
              if(s == "#"){
                  node->left = NULL;
              }
              else{
                  TreeNode* temp = new TreeNode(stoi(s));
                  node->left = temp;
                  q.push(node->left);
              }
             
              getline(str,s,',');
             
              if(s == "#"){
                  node->right = NULL;
              }
              else{
                  TreeNode* temp = new TreeNode(stoi(s));
                  node->right = temp;
                  q.push(node->right);
              }
             
         }
           
       }
        
     return root; 
    }
};
