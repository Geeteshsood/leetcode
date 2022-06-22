class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        
        priority_queue<int> pq;
        
        int n = heights.size();
        
        for(int i=0;i<n-1;i++){
            
            int gap = heights[i+1] - heights[i];
            
            if(gap <= 0)continue;
            
            if(gap <= bricks){
                
                bricks -= gap;
                pq.push(gap);
            }
            else{
                
                if(pq.size() == 0){
                    if(ladder > 0)ladder--;
                    else return i;
                    
                    continue;
                }
                
                if(gap < pq.top()){
                    bricks += pq.top() - gap;
                    pq.pop();
                    
                    if(ladder > 0)ladder--;
                    else return i;
                    
                    pq.push(gap);
                }
                else{
                    if(ladder > 0)ladder--;
                    else return i;
                }
                
            }
        }
        
     return n-1;   
    }
};