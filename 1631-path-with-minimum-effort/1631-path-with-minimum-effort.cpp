class Solution {
public:
    typedef pair<int,int> pi;
    typedef pair<int,pi> pii;
    
    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size() , n = heights[0].size();
        
        vector<vector<int>> diff(m,vector<int>(n,INT_MAX));
        
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        pq.push({0,{0,0}});
        diff[0][0] = 0;
        
        while(pq.size()){
            
            auto [i,j] = pq.top().second;
            int path = pq.top().first;
            
            pq.pop();
            
            if(path != diff[i][j])continue;
            
            for(auto &it : dir){
                
                int x = i + it[0];
                int y = j + it[1];
                
                if(isValid(x,y,m,n)){
                    
                    int sub = abs(heights[x][y]-heights[i][j]);
                    
                    int val = max(path,sub);
                    
                    if(val < diff[x][y]){
                        diff[x][y] = val;
                        pq.push({val,{x,y}});
                    }
                }
            }
        } 
        
        return diff[m-1][n-1];
    }
};