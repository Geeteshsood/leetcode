class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int l = 0 , r = n-1 , store = 0 , leftmax = INT_MIN , rightmax = INT_MIN;
        
        while(l <= r){
            
            if(height[l] <= height[r]){
                
                if(height[l] >= leftmax)leftmax = height[l];
                else store += leftmax - height[l];
                
                l++;
            }
            else{
                
                if(height[r] >= rightmax)rightmax = height[r];
                else store += rightmax - height[r];
                
                r--;
            }
            
        }
        
       return store; 
    }
};