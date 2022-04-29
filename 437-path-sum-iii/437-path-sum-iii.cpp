class Solution {
public:
    typedef long long ll;
    
    unordered_map<ll,ll> mp;
    ll cnt = 0 , sum = 0;
    
    void dfs(TreeNode* root,ll target){
       
        if(root == NULL)return ;
        
        sum += root->val;
    
        if(mp.count(sum - target)){
            cnt += mp[sum-target];
        }
        
        mp[sum]++;
        
        dfs(root->left,target);
        dfs(root->right,target);
        
        if(mp[sum] == 1)mp.erase(sum);
        else mp[sum]--;
        
        sum -= root->val;
        
    }
    
    ll pathSum(TreeNode* root, ll target) {
        
        mp[0] = 1;
        dfs(root,target);
        
        return cnt;
    }
};