class Solution {
public:
    
    typedef pair<int,int> pi;
    typedef pair<int,pi> pii;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        int m = nums1.size() , n = nums2.size();
        
        for(int i=0;i<m;i++){
            int sum = nums1[i] + nums2[0];
            pq.push({sum,{i,0}});
        }
        
        int cnt = 0;
        vector<vector<int>> ans;
        
        while(cnt < k && pq.size()){
            
           pii cur = pq.top();
            
           int sum = cur.first;
           int x = cur.second.first , y = cur.second.second;
            
           pq.pop();
            
           cnt++;
            
           ans.push_back({nums1[x],nums2[y]});
            
           if(y != n-1){
               y++;
               pq.push({nums1[x] + nums2[y],{x,y}});
           }
             
        }
        
      return ans;  
    }
};