class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n);
        
        int x = 0, y = 1;
        
        for(auto &i : nums){
            
            if(i > 0){
                ans[x] = i;
                x+=2;
            }
            else{
                ans[y] = i;
                y+=2;
            }
            
        }
        
      return ans;  
    }
};