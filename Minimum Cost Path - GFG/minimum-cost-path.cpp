// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    typedef pair<int,int> pi;
    typedef pair<int,pi> pii;

    bool isValid(int i,int j,int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int m = grid.size() , n = grid[0].size();
        
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        
        cost[0][0] = grid[0][0];
        
        priority_queue<pii,vector<pii>,greater<pii> >pq;
        pq.push({cost[0][0],{0,0}});
        
        while(pq.size()){
            
            int size = pq.size();
            
            for(int k=0;k<size;k++){
                
                int dist = pq.top().first;
                int i = pq.top().second.first, j = pq.top().second.second;
                
                pq.pop();
                
                if(cost[i][j] != dist)continue;
                
                for(auto &it : dir){
                    
                    int x = i + it[0];
                    int y = j + it[1];
                    
                    if(isValid(x,y,m,n) && cost[x][y] > dist + grid[x][y]){
                        
                        cost[x][y] = dist + grid[x][y];
                        
                        pq.push({cost[x][y],{x,y}});
                    }
                    
                }
            }
        }
        
        return cost[m-1][n-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends