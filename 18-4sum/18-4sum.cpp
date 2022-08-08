class Solution {
public:
    typedef long long ll;
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        ll n = nums.size();
        
        for(ll i=0;i<n;i++){
            
            while(i > 0 && i < n && nums[i] == nums[i-1])i++;
            
            for(ll j=i+1;j<n;j++){
                
                while(j > i+1 && j < n && nums[j] == nums[j-1])j++;
                
                ll x = j+1 , y = n-1;
                
                while(x < y){
                    
                   ll left = nums[i] + nums[j];
                   ll right = nums[x] + nums[y];
                    
                   ll sum = target - right;
                       
                   if(sum == left){
                       ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                   }
                    
                   if(left  >= sum){
                       while(y > x && nums[y] == nums[y-1])y--;
                       y--;
                   }
                   else{
                        while(x < n-1 && nums[x] == nums[x+1])x++;
                        x++;
                   }
                    
                }
  
            }
        }
        
        return ans;
    }
};