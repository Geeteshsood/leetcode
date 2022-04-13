class Solution {
public:
    
    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size() , n = heights[0].size();
        vector<vector<int>> diff(m,vector<int>(n,INT_MAX));
        
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        diff[0][0] = 0;
        
        while(q.size()){
            
            int i = q.front().first.first;
            int j = q.front().first.second;
            int k = q.front().second;
            
            q.pop();
            
            if(k != diff[i][j])continue;
            
            for(auto &it : dir){
                
                int x = i + it[0];
                int y = j + it[1];
                
                if(isValid(x,y,m,n)){
                    
                    int sub = abs(heights[x][y]-heights[i][j]);
                    
                    int val = max(k,sub);
                    
                    if(val < diff[x][y]){
                        diff[x][y] = val;
                        q.push({{x,y},val});
                    }
                }
            }
            
        } 
        
        return diff[m-1][n-1];
    }
};