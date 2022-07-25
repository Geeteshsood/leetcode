class Solution {
public:
     typedef pair<int,int> pi;   

    int minCostConnectPoints(vector<vector<int>>& points) {
            
        int n=points.size();    

        vector<pair<int,pair<int,int>>> res;

       int ans = 0;
        
       priority_queue<pi,vector<pi>,greater<pi>> pq;
        
       vector<int> mst(n,false),dist(n,INT_MAX);
      
          pq.push({0,0});
          dist[0] = 0;
          
          while(pq.size()){
              
            int i = pq.top().second;
            int path = pq.top().first;
            pq.pop();
        
            if(!mst[i])mst[i] = true;
            else continue;
            
            ans += path;
            
            for(int j=0;j<n;j++){
                
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]); 
                
                if(!mst[j] && wt < dist[j]){
                    dist[j] = wt;
                    pq.push({wt,j});
                }
            }
              
          }
       
     return ans; 
    }
};