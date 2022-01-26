class Solution {
public:
    
    vector<int> res1,res2;
    
    void find1(TreeNode* root1){
        
        if(root1 == NULL){
            return ;
        }
        
        find1(root1->left);
        res1.push_back(root1->val);
        find1(root1->right);
    }
    
     void find2(TreeNode* root2){
        
        if(root2 == NULL){
            return ;
        }
        
        find2(root2->left);
        res2.push_back(root2->val);
        find2(root2->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        find1(root1);
        find2(root2);
        
        int m = res1.size() , n = res2.size();
        vector<int> ans;
        
        int i = 0 , j = 0;
        
        while(i < m && j < n){
            
            ans.push_back(min(res1[i],res2[j]));
            
            if(res1[i] < res2[j])i++;
            else j++;
            
        }
        
        while(i<m){
            ans.push_back(res1[i]);
            i++;
        }
        
        while(j<n){
            ans.push_back(res2[j]);
            j++;
        }
        
        return ans;
    }
};