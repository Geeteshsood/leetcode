class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
           vector<int> v(2,0);
           map<int,vector<pair<int,int>>> m;
            
           for(int i=0;i<flights.size();i++){
              for(int j=0;j<flights[i].size();j++){
                 m[flights[i][0]].push_back({flights[i][1],flights[i][2]});
              } 
           }
            
            vector<int> dist(n,INT_MAX);
            dist[src]=0;
       
            queue<pair<int,int>> q;
            q.push({src,0});
            
         while(!q.empty()){  
            int size=q.size();   
            while(size!=0){
                
               int node=q.front().first; 
               int val=q.front().second;
               q.pop();
               if(k<0){
                   if(dist[dst]!=INT_MAX)return dist[dst];
                   else return -1;
               }
               for(auto it:m[node]){
                   v[0]=it.first;
                   v[1]=it.second;
                   if(val+v[1]<dist[v[0]]){
                       dist[v[0]]=val+v[1];
                       q.push({v[0],dist[v[0]]});
                   }
               }
               size--;     
            } 
            k--;     
         } 
            
        if(dist[dst]!=INT_MAX)return dist[dst];
            
 return -1;                             
    }
};