class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size(),mini = INT_MAX , maxi = INT_MIN;
        
        if(n == 1)return 0;
        
        if(nums[0] > nums[1]){
            mini = min(mini,nums[0]);
            maxi = max(maxi,nums[0]);
        }
        
        for(int i=1;i<n-1;i++){
            if(nums[i] < nums[i-1] || nums[i] > nums[i+1]){
                 mini = min(mini,nums[i]);
                 maxi = max(maxi,nums[i]);
            }
        }
        
        if(nums[n-1] < nums[n-2]){
             mini = min(mini,nums[n-1]);
             maxi = max(maxi,nums[n-1]);
        }
        
        // cout<<mini<<" "<<maxi<<endl;
        
        if(mini == INT_MAX)return 0;
        
        int j = 0 , k = 0;
        bool set = false;
        
        for(int i=0;i<n;i++){
            if(mini < nums[i]){
                 j = i;
                 break;
            }
        }
    
        for(int i=n-1;i>=0;i--){
            if(maxi > nums[i]){
                k = i;
                break;
            }
        }
        // cout<<j<<" , "<<k<<endl;
        return k-j+1;
    }
};