class Solution {
public:
    typedef long long ll;
    
    int widthOfBinaryTree(TreeNode* root) {
        
        ll ans = 1;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        
        while(q.size()){
            
            ll size = q.size() , left = INT_MAX , right = INT_MIN;
            ll curmin =  q.front().second;
            
            for(ll g=0;g<size;g++){
                
                TreeNode* node = q.front().first;
                ll id = q.front().second - curmin;
                
                q.pop();
                
                left = min(left,id);
                right = max(right,id);
                
                if(node->left)q.push({node->left,2*id});
                if(node->right)q.push({node->right,2*id+1});
                
            }
            // cout<<left<<" "<<right<<endl;
            if(left != right )ans = max(ans , right-left+1);
        }
        
        return ans;
    }
};