
class Solution {
public:
    
    int search(int i,int j,vector<int> &pre){
        
        int ans = i , val = pre[i];
        int start = i+1,end = j;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(val >= pre[mid]){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
                
        }
        
        return ans;
    }
    
    TreeNode* find(int st,int end,vector<int> &pre){
        
        if(st > end)return NULL;
        
        int loc = search(st,end,pre);
        
        TreeNode* root = new TreeNode(pre[st]);
        
        root->left = find(st+1,loc,pre);
        root->right = find(loc+1,end,pre);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        int n = pre.size();
        return find(0,n-1,pre);
    }
};