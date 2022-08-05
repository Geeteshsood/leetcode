class Solution {
public:
    
     bool allocate(vector<int> &weights,int mid,int days){
        
        int n = weights.size();
        int load = 0 , d = 0;
        
        for(int i=0;i<n;i++){
            
            if(load + weights[i] <= mid){
                load += weights[i];
            }
            else{
                load = 0;
                i--;
                d++;
                
                if(d >= days)return false;
            
            }
            
        }
        
     return true;
    }
    
    int search(int low,int high ,vector<int> &weights,int days){
        
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(allocate(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
       int n = weights.size();
       int low = -1 , high = 0;
       
       for(int i=0;i<n;i++){
          low = max(low,weights[i]);
          high += weights[i];
       }
       
       return  search(low,high,weights,days);
        
    }
};