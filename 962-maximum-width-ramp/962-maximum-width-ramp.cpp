class Solution {
public:
    
    int search(int i,vector<int> &v,vector<int> &nums){
        
        int n = v.size();
        
        int start = 0 , end = n-1 , ans = -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(nums[v[mid]] >= nums[i]){
                // if(nums[i] == 0)cout<<v[mid]<<" ** ";
                ans = v[mid];
                end = mid - 1;
            }
            else start = mid + 1;
            
        }
//         if(nums[i] == 0)cout<<endl;
//         cout<<nums[i]<<" "<<endl;
//         for(auto &x : v)cout<<nums[x]<<" ";
//         cout<<endl;
//         cout<<ans<<endl;
        
        return ans;
    }
    
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size() , ans = INT_MIN;
        vector<int> v;
        
        for(int i=n-1;i>=0;i--){
            
            if(v.size()){
                int x = search(i,v,nums);
                if(x != -1)ans = max(ans,x-i);
            }
            
            if(v.size()){
                if(nums[i] > nums[v.back()])v.push_back(i);
            }
            else v.push_back(i);
            
        }
        
        return ans==INT_MIN?0:ans;
    }
};