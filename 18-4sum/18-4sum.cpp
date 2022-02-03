class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
             sort(nums.begin(),nums.end());

             vector<vector<int>> ans;
        
             int n = nums.size() , i = 0;
        
            for(int i=0;i<n;i++){
                
                while(i>0 && i<n && nums[i] == nums[i-1])i++;  
                
                for(int j=i+1;j<n;j++){
                    
                    while(j > i+1 && j<n && nums[j] == nums[j-1])j++;
                    
                    int x = j+1 , y = n-1;
                    
                    while(x < y){
                        
                       int  left = nums[i] + nums[j];
                       int right = nums[x] + nums[y];
                       
                       if(left == target - right){
                           ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                       }
                        
                       if(left <= target - right){
                           while( x<y && nums[x] == nums[x+1])x++;
                           x++;
                       }
                       else{
                           while( x<y && nums[y] == nums[y-1])y--;;
                           y--;
                       }
                    } 
  
                }
            }
        
        return ans;
    }
};