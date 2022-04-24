class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        
        int m = f.size() , n = s.size();
        
        vector<vector<int>> res;
        
        int i=0,j=0;
        
        while(i<m && j<n){
            
          int x = max(f[i][0],s[j][0]);
          int y = min(f[i][1],s[j][1]);
            
          if(x <= y){
              res.push_back({x,y});
          } 
            
          if(f[i][1] < s[j][1]){
              i++;
          }
          else j++;
            
        }
        
     return res;        
    }
};