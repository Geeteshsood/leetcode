class Solution {
public:
    
    typedef pair<TreeNode*,int> pi;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<int>> mp;
        
        queue<pi> q;
        q.push({root,0});
        
        while(q.size()){
            
            int size = q.size();
            map<int,vector<int>> temp;
            
            for(int g=0;g<size;g++){
                
                TreeNode* node = q.front().first;
                int hz = q.front().second;
                
                temp[hz].push_back(node->val);
                
                q.pop();
                
                if(node->left){
                    q.push({node->left,hz-1});
                }
                
                if(node->right){
                    q.push({node->right,hz+1});
                }
            }
            
            for(auto &it : temp){
                sort(it.second.begin(),it.second.end());
                
                for(auto &val : it.second){
                    mp[it.first].push_back(val);
                }
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto &it : mp){
            vector<int> res;
            for(auto &val : it.second){
                res.push_back(val);
            }
            ans.push_back(res);
        }
        
       return ans; 
    }
};