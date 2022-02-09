class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            
            if(i > 0){
                while(i<n && nums[i] == nums[i-1])i++;
            }
            
            for(int j=i+1;j<n;j++){
                
                if(j>i+1){
                    while(j<n && nums[j] == nums[j-1])j++;
                }
                
                if(j<n && abs(nums[j]-nums[i]) == k){
                    cnt++;
                }
            }
        }
        
        
     return cnt;
    }
};