class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size() , pro = 1;
        
        int cnt = 0 , j = 0;
        
        for(int i=0;i<n;i++){
            
            if(pro*nums[i] >= k){
                cnt += (i-j);
                if(j<i){
                    pro = pro/nums[j];
                    i--;
                }
                j++;
            }
            else pro = pro*nums[i];
        }
        
        int x = n-j;
        
       return cnt + ((x*(x+1))/2); 
    }
};