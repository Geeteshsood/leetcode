class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
             sort(nums.begin(),nums.end());

             vector<vector<int>> ans;
        
             int n = nums.size() , i = 0;
        
            while(i<n){
                
                int j = i+1;
                while(j<n){
                    
                    int x = j+1 , y = n-1;
                    
                    while(x < y){
                        
                       int  left = nums[i] + nums[j];
                       int right = nums[x] + nums[y];
                       
                       if(left == target - right){
                           ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                       }
                        
                       if(left <= target - right){
                           x++;
                           while( x<y && nums[x] == nums[x-1])x++;
                       }
                       else{
                           y--;
                           while( x<y && nums[y] == nums[y+1])y--;;
                       }
                    } 
                    j++;
                    while( j<n && nums[j] == nums[j-1]){
                        j++;
                    }
                }
                i++;
              while(i<n && nums[i] == nums[i-1])i++;  
            }
        
        return ans;
    }
};