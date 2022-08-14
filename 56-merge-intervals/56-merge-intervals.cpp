class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in ) {
        
        vector<vector<int>> res;
        
        sort(in.begin(),in.end());
        
        int n = in.size();
        
        int st = in[0][0] , end = in[0][1];
        
        for(int i=1;i<n;i++){
            
            int u = in[i][0] , v = in[i][1];
            
            if(end >= u){
                end = max(end,v);
            }
            else{
                res.push_back({st,end});
                st = in[i][0],end = in[i][1];
                i--;
            }
        }
        
        res.push_back({st,end});
        
        return res;
    }
};