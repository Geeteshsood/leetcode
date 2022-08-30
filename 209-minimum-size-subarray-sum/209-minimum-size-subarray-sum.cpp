class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n);
        
        for(int i=0;i<n;i++){
            if(i == 0)prefix[i] = nums[i];
            else prefix[i] = prefix[i-1] + nums[i];
        }
        
        int len = INT_MAX;
        
        int i = 0,j = 0;
        int sum = 0;
        
        while(i < n){
            
            sum += nums[i];
            
            int start = 0 , end = i-1,ans = -1;
            
            while( start <= end){
                
                int mid = start + (end - start)/2;
                
                int val = sum - prefix[mid];
                
                if(val >= target){
                    ans = mid;
                    start = mid+1;
                }
                else end = mid-1; 
            }
            
            if(ans != -1)len = min(len,i-ans);
            else if(sum >= target)len = min(len,i+1);
            
            i++;
        }
        
        if(len == INT_MAX)len = 0;
        
        return len;

    }
};