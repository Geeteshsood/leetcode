class Solution {
public:
    
vector<vector<int>> find(int start,int k,int n,int cnt){
        
        if(n == 0 && cnt == k){
            return {{}};
        }
        
        vector<vector<int>> temp;
        
        for(int i=start;i<=9;i++){
            if(cnt + 1 > k || n-i < 0)continue;
            else if(cnt + 1 == k && n-i != 0)continue;
            
            auto res = find(i+1,k,n-i,cnt+1);
            
            for(int j=0;j<res.size();j++){
                res[j].push_back(i);
                temp.push_back(res[j]);
            }
        }
        
        return temp;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        return find(1,k,n,0);

    }
};