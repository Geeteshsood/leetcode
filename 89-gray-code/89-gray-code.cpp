class Solution {
public:
    
    vector<int> find(int n){
        
       if(n == 1)return {0,1};
        
        auto ans = find(n-1);
        
        int sz = ans.size();
        int val = 1<<(n-1);
        
        for(int i=sz-1;i>=0;i--){
            
            ans.push_back(val + ans[i]);
        }
        
        return ans;
    }
    
    vector<int> grayCode(int n) {
        
        return find(n);
    }
};